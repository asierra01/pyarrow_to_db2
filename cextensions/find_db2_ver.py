

import os

def print_ver(ver):
    if len(ver) == 12:
        major = sql_ver[7:9]
        major_ver = sql_ver[9:10]
        minor = sql_ver[-1]
        minor_ver = "0"

    else:
        major = sql_ver[7:9]
        major_ver = sql_ver[9:11]
        minor = sql_ver[11:13]
        minor_ver = sql_ver[13:15]

    try:
        major_int = int(major)
    except:
        pass

    try:
        major_ver_int = int(major_ver)
    except:
        pass

    try:
        minor_int = int(minor)
    except:
        pass    

    try:
        minor_ver_int = int(minor_ver)
    except:
        pass    

    try:
       #print(sql_ver, major_int, major_ver_int, minor_int, minor_ver_int)
       return ("%s.%s.%s.%s" % (major_int, major_ver_int, minor_int, minor_ver_int))
    except :
       pass
    return ""

if os.environ.get("DB2INCLUDE") is not None:
    db2include = os.environ.get("DB2INCLUDE")
    sql_h = open(os.path.join(db2include, "sql.h")).read()
    ok = True
    sql_ver = ""
    str_find = "SQL_REL"
    pos_stop = sql_h.find("SQL_FUTUREL")
    sql_ver_pos = 0
    while ok:
        sql_ver_pos = sql_h.find(str_find, sql_ver_pos)
        if sql_ver_pos > pos_stop:
            break
        if (sql_ver_pos != -1):
            blank = sql_h.find(" ", sql_ver_pos)
            sql_ver = sql_h[sql_ver_pos:blank]
            print_ver(sql_ver)
            sql_ver_pos += 12
    ret = print_ver(sql_ver)
    print(ret)
else:
    print("DB2INCLUDE not defined")
