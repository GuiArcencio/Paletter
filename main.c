#define STBI_FAILURE_USERMSG
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "stb_image.h"
#include "stb_image_write.h"

#include "palette.h"
#include "format.h"

#include <stdio.h>

void paletter_error(const char *errorstring);

int main(int argc, char **argv) 
{
    if (argc != 4) 
        paletter_error("Incorrect usage. Try this:\npaletter <path-to-image> <path-to-palette> <output-file>");

    int width, height, num_channels;
    unsigned char *pixel_data = stbi_load(argv[1], &width, &height, &num_channels, 4);
    if (!pixel_data) 
        paletter_error(stbi_failure_reason());

    Color *color_list = read_palette_file(argv[2]);
    if (!color_list)
        paletter_error("Unable to read palette file");

    Img_Format imgf;
    if (parse_img_format(argv[3], &imgf))
        paletter_error("Output file format not supported/recognized. Supported output formats:\n-PNG (.png)\n-JPG (.jpg, .jpeg, .jpe, .jif, .jfif, .jfi)\n-BMP (.bmp, .dib)\n-TGA (.tga, .targa, .tpic)");

    apply_palette(pixel_data, width, height, color_list);

    // Check for file types
    switch (imgf)
    {
        case PNG:
            stbi_write_png(argv[3], width, height, 4, pixel_data, width * 4);
            break;
        case JPG:
            stbi_write_jpg(argv[3], width, height, 4, pixel_data, 95);
            break;
        case BMP:
            stbi_write_bmp(argv[3], width, height, 4, pixel_data);
            break;
        case TGA:
            stbi_write_tga(argv[3], width, height, 4, pixel_data);
            break;        
    }
    

    sb_free(color_list);
    free(pixel_data);
    return 0;
}

void paletter_error(const char *errorstring)
{
    fprintf(stderr, "Error: %s\n", errorstring);
    exit(1);
}
