#include "io.h"

void writeXY(int x, int y, char *text, char color)
{
    char *screenBuffer = (char *)0xb800;
    int pos = x*2 + y*2*80;
    for(int i = 0; i < strlen(text); i++)
    {
        screenBuffer[pos  ] = text[i];
        screenBuffer[pos+1] = color;
        pos += 2;
    }
}
