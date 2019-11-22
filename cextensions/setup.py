import os
import sys
import pprint
import platform
import logging
import logging.handlers
#from distutils import log
from setuptools.command.build_ext import build_ext
from distutils.dir_util import remove_tree
import errno
import setuptools
from setuptools import Extension
from distutils.sysconfig import get_python_inc, get_python_lib
import distutils
import site
from texttable import Texttable
import numpy
import pybind11
import glob
from ctypes import cdll
import platform

import site

print (site.getsitepackages())

sitepackages = site.getsitepackages()
for sitepackage in sitepackages:
    pyarrow_path = os.path.join(sitepackage, "pyarrow")
    if os.path.exists(pyarrow_path):
        os.environ["PATH"] += ";"+pyarrow_path
        print("found !!!")
        print("%s" % pprint.pformat(os.environ["PATH"]))
        if platform.system() == "Windows":
            lib = cdll.LoadLibrary("lib.cp37-win_amd64.pyd")
            lib.PyInit_lib()

import pyarrow.lib
import pyarrow

try:
    os.mkdir('log')
except OSError as e:
    if e.errno != errno.EEXIST:
        print ("creating directory 'log'  OSError %s" % e)

try:
    os.remove(os.path.join("log", "build.log"))
except OSError:
    pass

format_hdlr = "%(asctime)s %(levelname)6s:%(lineno)4s - %(funcName)10s() %(message)s  "

#file_hdlr = logging.handlers.RotatingFileHandler('build.log',maxBytes=5000000, backupCount = 5)
# create console handler and set level to debug
console_hdlr = logging.StreamHandler()
console_hdlr.setLevel(logging.INFO)


log_formatter = logging.Formatter(format_hdlr, "%H:%M:%S") # "%Y-%m-%d %H:%M:%S"

hdlr = logging.handlers.RotatingFileHandler(
    os.path.join("log", "build.log"), 
    maxBytes=10000000, 
    backupCount=3)
hdlr.setLevel(logging.INFO)

console_hdlr.setFormatter(log_formatter)
hdlr.setFormatter(log_formatter)
log = logging.getLogger(__name__)
log.setLevel(logging.INFO)
#log.addHandler(file_hdlr)
log.addHandler(console_hdlr)
log.addHandler(hdlr)

DB2PATH = os.environ.get("DB2PATH", None)


if DB2PATH is None or DB2PATH == '':
    log.error("DB2PATH is None")
    sitepackages = site.getsitepackages()
    for sitepackage in sitepackages:
        cli_driver = os.path.join(sitepackage, 'clidriver', 'include')
        DB2PATH = os.path.join(sitepackage, 'clidriver')
        sqlcli_h = os.path.join(cli_driver, 'sqlcli.h')
        log.debug("checking here '%s'" % sqlcli_h)
        if os.path.exists(sqlcli_h):
            log.info("Found it here '%s'" % sqlcli_h)
            os.environ['DB2INCLUDE'] = cli_driver
            log.info("using DB2PATH '%s'" % DB2PATH)
            break
else:
    log.info("using DB2PATH '%s'" % DB2PATH)

if DB2PATH is None:
    log.error("Cant find sqlcli.h using DB2PATH")
    sys.exit(0)

def provide_db2_include_dir():
    db2_include = os.environ.get('DB2INCLUDE', None)
    log.info("env DB2INCLUDE '%s'" % db2_include)
    return db2_include



def provide_sample_cli_dir():

    cwd = os.getcwd()
    if platform.system() == "Windows":
        platform_path = "win64"
    elif platform.system() == "Linux":
        platform_path = "lin64"
    elif platform.system() == "Darwin":
        platform_path = "osx"

    sample_cli_dir = os.path.join(cwd, platform_path)

    log.debug("sample_cli_dir '%s'" % sample_cli_dir)
    return sample_cli_dir


if platform.system() == "Windows":
    #from setuptools import msvc
    #msvc = msvc.msvc14_get_vc_env("x64")
    #log.info (pprint.pformat(msvc))
    #sys.exit(0)
    libraries = ["db2api", "parquet"]
    extra_link_args = [#  "/VERBOSE",
                       "/ignore:4197",  #4197 export 'initconnect_odbc' specified multiple times; using first specification
                       "/MACHINE:X64"]
    extra_compile_args = [
                    # "-v", #verbose
                    # "-fopenmp",
                    # "-O3",
                    #"/wd9025", #9025 cl : Command line warning D9025 : overriding '/W3' with '/w'
                    "/favor:AMD64",
                    "/w",  # no warnings
                    "-D_CRT_SECURE_NO_WARNINGS",
                    "-DNOMINMAX",
                    "-DWIN32",
                    "-DSPCLIENT_PYTHON"]
    library_dirs = ["%s/lib" % DB2PATH, "Release"]


    extra_objects = []
else:
    lib64_path   = os.path.join(DB2PATH, "lib64")
    lib_path     = os.path.join(DB2PATH, "lib")
    include_path = os.path.join(DB2PATH, "include")

    link = os.path.islink(lib64_path)
    log.debug("lib64_path %s is a link %s" % (lib64_path, link))
    exist = os.path.exists(lib64_path)
    log.debug("lib64_path %s exist %s" % (lib64_path, exist))
    if not (exist or link):
        log.error("lib64_path doesnt exist '%s'" % lib64_path)
        if os.path.exists(lib_path):
            log.info("Lets use lib path '%s'" % lib_path)
            lib64_path = lib_path
        else:
            log.error("lib_path doesnt exist '%s'" % lib_path)
            sys.exit(0)
    else:
        log.debug("lib64_path '%s'" % lib64_path)

    if not os.path.exists(include_path):
        log.error("include_path doesnt exist '%s'" % include_path)
        sys.exit(0)

    library_dirs = [lib64_path]
    libraries = ["db2"]

    extra_objects = []
    if os.environ.get('CXXFLAGS'):
        os.environ['CXXFLAGS'] += ' std=c++11'
    else:
        os.environ['CXXFLAGS'] = 'std=c++11'

    extra_link_args = [  "-v", #  verbose
                       "-DSOME_DEFINE_OPT"]
    extra_compile_args = [#  "-v", # verbose # too much verbosity
                          # "-fopenmp",
                          "-O3",
                          "-w",  # no warnings
                          # "-Wstrict-prototypes",
                          # "-Wimplicit-function-declaration",
                          # "-I/usr/local/include",
                          # "-I%s/samples/cli" % DB2PATH,
                          "-DSPCLIENT_PYTHON"]

libraries.extend(pyarrow.get_libraries())
library_dirs.extend(pyarrow.get_library_dirs())

if sys.version_info > (3,):
    export_symbols = ['PyInit_spclient_python']
else:
    export_symbols = ['initspclient_python']


def get_utilcli_c_location():
    utilcli_c_location = os.path.join(provide_sample_cli_dir(), "utilcli.cpp")
    return utilcli_c_location


class MyBuildExt(build_ext):
    """
    My_build_ext was only coded to exploit function copy_tree and copy the .pyd to local directory
    """
    def __init__(self, *args, **kwargs):
        # log.info("args '%s' kwargs '%s' type *args %s" % (args, kwargs, type(*args)))
        # log.info("%s " % (type(*args)))
        # log.info("%s \n%s" % (type(*args), pprint.pformat(dir(*args))))

        long_str = ""
        for user_option in build_ext.user_options:
            long_str += "%s %s %s \n" % user_option

        log.debug("build_ext.user_option \n\n%s\n" % long_str)
        build_ext.__init__(self, *args)
        if self.verbose:
            log.info("verbosity %s" % self.verbose) # python setup.py --quiet build

    def set_table(self):
        mytable = Texttable()
        mytable.set_deco(Texttable.HEADER)
        mytable.set_cols_dtype(['t', 't'])
        header_str = "label value"
        mytable.set_header_align(['t', 't'])
        mytable.header(header_str.split())
        mytable.set_cols_width( [35, 120])
        return mytable


    def log_extensions(self, extensions, mytable):
        log.debug("extensions %s" % extensions)
 
 
        for extension in extensions:
            log.debug("extension %s" % dir(extension))

            if extension.language:
                row = ["extension.language", "'%s'" % extension.language]
                mytable.add_row(row)
                #log.info("language             '%s'" % extension.language)

            row = ["extension.sources", "%s" % pprint.pformat(extension.sources)]
            mytable.add_row(row)

            if extension.depends:
                row = ["depends", "%s" % extension.depends]
                mytable.add_row(row)

            if extension.define_macros:
                row = ["extension.define_macros", "%s" % extension.define_macros]
                mytable.add_row(row)

            mytable.add_row(["extension.libraries","%s" % extension.libraries])

            if extension.include_dirs:
                for include_dir in extension.include_dirs:
                    mytable.add_row(["extension.include_dir",   "%s" % include_dir])

            if extension.library_dirs:
                for library_dir in extension.library_dirs:
                    mytable.add_row(["extension.library_dir",   "%s" % library_dir])

            mytable.add_row(["extension._file_name", "%s" % extension._file_name])

            mytable.add_row(["extension.export_symbols", "%s" % extension.export_symbols])

            if extension.extra_objects:
                mytable.add_row(["extension.extra_objects", "%s" % extension.extra_objects])

            if extension.undef_macros:
                mytable.add_row(["undef_macros", "%s" % extension.undef_macros])

            mytable.add_row(["extension.extra_link_args",    "%s" % pprint.pformat(extension.extra_link_args)])
            mytable.add_row(["extension.extra_compile_args", "%s" % pprint.pformat(extension.extra_compile_args)])
            mytable.add_row(["extension.extension.name",     "%s" % extension.name])


            if extension.runtime_library_dirs:
                for runtime_library_dir in extension.runtime_library_dirs:
                    mytable.add_row(["extension.runtime_library_dirs", "%s" % runtime_library_dir])


    def log_details(self):

        mytable = self.set_table()
        mytable.add_row(["build_lib", "%s" % self.build_lib])
        mytable.add_row(["plat_name", "%s" % self.plat_name])

        if self.library_dirs:
            for library_dir in self.library_dirs:
                mytable.add_row(["library_dirs", "%s" % library_dir])

        if self.libraries:
            mytable.add_row(["libraries", "%s" % self.libraries])

        if self.include_dirs:
            for include_dir in self.include_dirs:
                mytable.add_row(["include_dirs", "%s" % include_dir])

        if self.get_libraries(self):
            mytable.add_row(["get_libraries", "%s" % self.get_libraries(self)])

        self.compiler.define_macro(name="C++2031", value="IsOverrated")
        log.debug("compiler.macros                  '%s'" % self.compiler.macros)
        self.compiler.undefine_macro("C++2031")

        if self.compiler.runtime_library_dirs:
            mytable.add_row(["compiler.runtime_library_dirs", "%s" % self.compiler.runtime_library_dirs])

        if self.compiler.library_dirs:
            for library_dir in self.compiler.library_dirs:
                mytable.add_row(["compiler.library_dirs", "%s" % library_dir])

        mytable.add_row(["compiler.macros",  "%s" % self.compiler.macros])
        mytable.add_row(["compiler.output_dir", "%s" % self.compiler.output_dir])
        mytable.add_row(["compiler.shared_lib_extension", "%s" % self.compiler.shared_lib_extension])

        if hasattr(self.compiler, "dylib_lib_extension"):
            mytable.add_row(["compiler.dylib_lib_extension", "%s" % self.compiler.dylib_lib_extension])

        if hasattr(self.compiler, "dylib_lib_format"):
            mytable.add_row(["compiler.dylib_lib_format", "%s" % self.compiler.dylib_lib_format])

        if self.compiler.exe_extension:
            mytable.add_row(["compiler.exe_extension", "%s" % self.compiler.exe_extension])

        if hasattr(self.compiler, "compiler_cxx"):
            mytable.add_row(["compiler.compiler_cxx", "%s" % self.compiler.compiler_cxx])

        if hasattr(self.compiler, "compiler_so"):
            mytable.add_row(["compiler.compiler_so", "%s" % pprint.pformat(self.compiler.compiler_so)])

        if hasattr(self.compiler, "linker"):
            mytable.add_row(["compiler.linker", "%s" % self.compiler.linker])

        if hasattr(self.compiler, "mc"):
            mytable.add_row(["compiler.mc", "%s" % self.compiler.mc])

        if hasattr(self.compiler, "compiler"):
            mytable.add_row(["compiler.compiler", "%s" % pprint.pformat(self.compiler.compiler)])

        if hasattr(self.compiler, "cc"):
            mytable.add_row(["compiler.cc", "%s " % self.compiler.cc])

        mytable.add_row(["compiler.compiler_type",           "%s" % self.compiler.compiler_type])
        mytable.add_row(["compiler.shared_lib_format",       "%s" % self.compiler.shared_lib_format])
        mytable.add_row(["compiler.verbose",                 "%s" % self.compiler.verbose])

        if hasattr(self.compiler, "preprocessor"):
            mytable.add_row(["compiler.preprocessor",        "%s" % self.compiler.preprocessor])

        if hasattr(self.compiler, "linker_so"):
            mytable.add_row(["compiler.linker_so",            "%s" % pprint.pformat(self.compiler.linker_so)])

        if hasattr(self.compiler, "linker_exe"):
            if self.compiler.linker_exe:
                mytable.add_row(["compiler.linker_exe",  "%s" % self.compiler.linker_exe])

        if hasattr(self.compiler, "link_shared_object"):
            if self.compiler.link_shared_object:
                mytable.add_row(["compiler.link_shared_object",  "%s" % self.compiler.link_shared_object])

        if hasattr(self.compiler, "runtime_library_dirs"):
            mytable.add_row(["compiler.runtime_library_dirs",        "%s" % self.compiler.runtime_library_dirs])

        if hasattr(self.compiler, "executables"):
            if self.compiler.executables:
                mytable.add_row(["compiler.executables",  "%s" % pprint.pformat(self.compiler.executables)])

        if hasattr(self.compiler, "language_map"):
            if self.compiler.language_map:
                mytable.add_row(["compiler.language_map",  "%s" % pprint.pformat(self.compiler.language_map)])

        log.debug("compiler.shared_object_filename  '%s'" % self.compiler.shared_object_filename("juana"))

        if hasattr(self.compiler, "ldflags_shared"):
            mytable.add_row(["compiler.ldflags_shared",        "%s" % self.compiler.ldflags_shared])

        if hasattr(self.compiler, "compile_options"):
            mytable.add_row(["compiler.compile_options",        "%s" % self.compiler.compile_options])

        if hasattr(self.compiler, "plat_name"):
            if self.compiler.plat_name:
                mytable.add_row(["compiler.plat_name",  "%s" % self.compiler.plat_name])

        if hasattr(self.compiler, "EXECUTABLE"):
            if self.compiler.EXECUTABLE:
                mytable.add_row(["compiler.EXECUTABLE",  "%s" % self.compiler.EXECUTABLE])

        if hasattr(self.compiler, "SHARED_LIBRARY"):
            if self.compiler.EXECUTABLE:
                mytable.add_row(["compiler.SHARED_LIBRARY",  "%s" % self.compiler.SHARED_LIBRARY])

        if hasattr(self.compiler, "SHARED_OBJECT"):
            if self.compiler.EXECUTABLE:
                mytable.add_row(["compiler.SHARED_OBJECT",  "%s" % self.compiler.SHARED_OBJECT])

        if hasattr(self.compiler, "src_extensions"):
            if self.compiler.EXECUTABLE:
                mytable.add_row(["compiler.src_extensions",
                                 "%s" % self.compiler.src_extensions])

        if hasattr(self.compiler, "detect_language"):
            if self.compiler.detect_language:
                mytable.add_row(["compiler.detect_language test.cpp",
                                 "%s" % self.compiler.detect_language("test.cpp")])


        #if hasattr(self.compiler, "shared_object_filename"): # is a function
        #    if self.compiler.EXECUTABLE:
        #        mytable.add_row(["compiler.shared_object_filename",  "%s" % self.compiler.shared_object_filename])


        #if hasattr(self.compiler, "library_dir_option"): # is a function
        #    if self.compiler.library_dir_option:
        #        mytable.add_row(["compiler.library_dir_option",  "%s" % self.compiler.library_dir_option])


        #log.info("compiler %s" % dir(self.compiler))
        log.debug("compiler.library_filename          '%s'" % self.compiler.library_filename("juana"))

        self.log_extensions(self.extensions, mytable)
        mytable.add_row(["distutils.sysconfig.get_python_inc", "%s" % get_python_inc()])
        mytable.add_row(["distutils.sysconfig.get_python_lib", "%s" % get_python_lib()])
        mytable.add_row(["extension location", self.build_lib])
        mytable.add_row(["file_name_pyd", self.file_name_pyd])

        log.info("\n\n%s\n" % mytable.draw())

    def remove_old_build(self):

        for extension in self.extensions:
            self.file_name_pyd = extension._file_name
            if os.path.exists(self.file_name_pyd):
                if self.verbose > 0:
                    log.info("removing      '%s'" % self.file_name_pyd)
                    os.remove(self.file_name_pyd)
            else:
                log.warning("file_name_pyd %s not present" % self.file_name_pyd)

        log.info("removing tree '%s'" % self.build_lib)
        try:
            remove_tree(self.build_lib)
        except OSError as e:
            if e.errno not in  [errno.EEXIST, errno.ENOENT] :
                log.error("OSError '%s'" % e)


    def run(self):
        try:
            if self.verbose > 0:
                log.info("run")
            try:
                self.remove_old_build()
                build_ext.run(self)

                if self.verbose > 0 or self.verbose is None:
                    self.log_details()

            except Exception as e:
                log.error("Exception %s %s" % (type(e), e))
                self.log_details()
 
            try:
                self.copy_tree("%s" % self.build_lib, ".")
                self.copy_tree("%s" % self.build_lib, "..")
            except distutils.errors.DistutilsFileError as e: # cannot copy tree 'build\lib.win-amd64-3.6': not a directory
                log.error("DistutilsFileError '%s'" % e)

        except Exception as e:
            log.error("DistutilsPlatformError %s" % e)
            raise 


include_dirs = [provide_db2_include_dir(),
                pyarrow.get_include(),
                numpy.get_include(),
                pybind11.get_include(),
                os.getcwd(),
                os.path.join(os.getcwd(), "include"),
                provide_sample_cli_dir()]


if platform.system() == "Windows":
    pass
    #include_dirs.append(os.path.join(os.getcwd(), "include"))
else:
    # do I need to append lib dir
    # to library_dirs /usr/local/lib so that the linker find 
    # so far is linking without the append
    include_dirs.append('/usr/local/include')
    library_dirs.append('/usr/local/lib')

log.info("libraries %s" % libraries)
log.info("library_dirs \n%s" % pprint.pformat(library_dirs))
log.info("include_dirs \n%s" % pprint.pformat(include_dirs))
log.info("extra_objects \n%s" % pprint.pformat(extra_objects))
# define the extension module
sources = [get_utilcli_c_location()]
sources.extend(glob.glob("*.cpp"))
spclient_python_ext = Extension(name='spclient_python',
                               sources=sources,
                               libraries=libraries,
                               language="c++",
                               export_symbols=export_symbols,
                               library_dirs=library_dirs,
                               extra_objects=extra_objects,
                               extra_compile_args=extra_compile_args,
                               extra_link_args=extra_link_args,
                               include_dirs=include_dirs)

setuptools.setup(name='spclient_python',
                 version='1.0.0',
                 description='ibm_db python extensions',
                 author='Jorge Sierra',
                 author_email='asierra01@gmail.com',
                 cmdclass={'build_ext': MyBuildExt},
                 ext_modules=[spclient_python_ext])

