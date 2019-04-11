import logging.handlers
import os
import errno

try:
    os.mkdir('log')
except OSError as e:
    if e.errno != errno.EEXIST:
        print ("creating directory 'log'  OSError %s" % e)

try:
    os.remove(os.path.join("log", "build.log"))
except OSError:
    pass

format_hdlr = "%(asctime)s %(levelname)s:%(lineno)s - %(funcName)s() %(message)s  "

#file_hdlr = logging.handlers.RotatingFileHandler('build.log',maxBytes=5000000, backupCount = 5)
# create console handler and set level to debug
console_hdlr = logging.StreamHandler()
console_hdlr.setLevel(logging.INFO)
log_formatter = logging.Formatter(format_hdlr, "%H:%M:%S" ) # "%Y-%m-%d %H:%M:%S"

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
