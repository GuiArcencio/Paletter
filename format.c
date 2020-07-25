#include "format.h"
#include <string.h>

int parse_img_format(const char *filename, Img_Format *imgf)
{
    char *fmt = strchr(filename, '.');
    if (!fmt) return 1;

    if (!strcmp(fmt, ".png"))
    {
        *imgf = PNG;
        return 0;
    }
    else if (!strcmp(fmt, ".jpg") || !strcmp(fmt, ".jpeg") || !strcmp(fmt, ".jpe") || !strcmp(fmt, ".jif") || !strcmp(fmt, ".jfif") || !strcmp(fmt, ".jfi"))
    {
        *imgf = JPG;
        return 0;
    }
    else if (!strcmp(fmt, ".bmp") || !strcmp(fmt, ".dib"))
    {
        *imgf = BMP;
        return 0;
    }
    else if (!strcmp(fmt, ".tga") || !strcmp(fmt, ".targa") || !strcmp(fmt, ".tpic"))
    {
        *imgf = TGA;
        return 0;
    }

    return 1;
}