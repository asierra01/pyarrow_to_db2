
import os
import string
import warnings

def get_ext_filename(ext_name, debug=False):
    r"""Convert the name of an extension (eg. "foo.bar") into the name
    of the file from which it will be loaded (eg. "foo/bar.so", or
    "foo\bar.pyd").
    """
    from distutils.sysconfig import get_config_var
    ext_path = ext_name.split('.')
    # OS/2 has an 8 character module (extension) limit :-(
    if os.name == "os2":
        ext_path[len(ext_path) - 1] = ext_path[len(ext_path) - 1][:8]
    # extensions in debug_mode are named 'module_d.pyd' under windows
    with warnings.catch_warnings(record=True) as w:
       so_ext = get_config_var('SO')
    if os.name == 'nt' and debug:
        return os.path.join(*ext_path) + '_d' + so_ext
    return os.path.join(*ext_path) + so_ext

a =  get_ext_filename(ext_name='spclient_python')
print (a)