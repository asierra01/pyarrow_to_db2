

#ifndef WIN32
#include "win32_to_linux.h"
#include <string.h>
char * strcpy_s(char *dest, int size, const char *in_str)
{
    return strcpy(dest, in_str);
}

char * strncpy_s(char* dest, int size, const char *in_str, int len)
{
    return strncpy(dest, in_str, len);
}

char * strcat_s(char *dest, int len, const char *src)
{
    return strcat(dest, src);
}

//int sscanf_s( const char* buffer, const char* format, char * parm, int size )
//{
//    return sscanf( buffer, format, parm );
//}
#endif
