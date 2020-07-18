#include "palette.h"

Color *read_palette_file(const char *filename) 
{
    // Reads CSV file containing hex codes for the colors

    FILE *fp = fopen(filename, "r");
    if (!fp) return NULL;

    Color *color_list = NULL;
    unsigned int hex_color;
    char delim;
    do 
    {
        fscanf(fp, "%x", &hex_color);
        delim = fgetc(fp);
        Color new_color;
        new_color.B = hex_color % 256;
        hex_color >>= 8;
        new_color.G = hex_color % 256;
        hex_color >>= 8;
        new_color.R = hex_color % 256;
        sb_push(color_list, new_color);
    } while (delim == ',');

    fclose(fp);
    return color_list;
}

float color_variance(Color c1, Color c2)
{
    // Algorithm from https://www.compuphase.com/cmetric.htm
    float rm = (c1.R + c2.R) / 2.f;
    float dr = c1.R - c2.R;
    float dg = c1.G - c2.G;
    float db = c1.B - c2.B;

    return (2.f + rm/256.f) * dr * dr + 4.f * dg * dg + (2.f + (255.f - rm)/256.f) * db * db;
}

void apply_palette(unsigned char *data, int width, int height, Color *color_list)
{
    int i, j;
    for (i = 0; i < height; i++)
        for (j = 0; j < width; j++)
        {
            int index = (i*width + j) * 4;
            Color current_color;
            current_color.R = data[index];
            current_color.G = data[index + 1];
            current_color.B = data[index + 2];

            // Looks for a color in palette which minimizes distance from
            // the current pixel's color
            int min_p = 0;
            float min_variance = color_variance(current_color, color_list[0]);
            int p;
            for (p = 0; p < sb_count(color_list); p++)
            {
                float new_variance = color_variance(current_color, color_list[p]);
                if (new_variance < min_variance)
                {
                    min_p = p;
                    min_variance = new_variance;
                }
            }

            data[index] = color_list[min_p].R;
            data[index + 1] = color_list[min_p].G;
            data[index + 2] = color_list[min_p].B;
        }
}