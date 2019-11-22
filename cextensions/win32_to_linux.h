#pragma once

#ifndef WIN32
#ifdef __cplusplus
extern "C" {
#endif

#ifndef errno_t
typedef int                    errno_t;
#endif

#ifndef strcpy_s
char * strcpy_s(char *dest, int size, const char *in_str);
#endif
char * strncpy_s(char* dest, int size, const char *in_str, int len);
char * strcat_s(char *dest, int len, const char *src);
//int sscanf_s( const char* buffer, const char* format, char * parm, int size );

#ifdef __cplusplus
}
#endif

#endif


