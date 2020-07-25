#ifndef PALETTE_H
#define PALETTE_H

#include "stretchy_buffer.h"

#include <stdio.h>

typedef struct color 
{
    unsigned char R, G, B;
} Color;

Color *read_palette_file(const char *filename);

float color_variance(Color c1, Color c2);

void apply_palette(unsigned char *data, int width, int height, Color *color_list);

#endif /* PALETTE_H */