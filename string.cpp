#include "string.h"

int strlen(const char *string)
{
    int length = 0;

    while(string[0] != '\0')
    {
        length++;
        string++;
    }
    
    return length;
}
