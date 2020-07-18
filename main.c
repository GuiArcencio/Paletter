#define STBI_FAILURE_USERMSG
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "stb_image.h"
#include "stb_image_write.h"

#include "palette.h"

#include <stdio.h>

void paletter_error(const char *errorstring);

int main(int argc, char **argv) 
{
    if (argc != 3) 
        paletter_error("Incorrect usage. Try this:\npaletter <path-to-image> <path-to-palette>");

    int width, height, num_channels;
    unsigned char *pixel_data = stbi_load(argv[1], &width, &height, &num_channels, 4);
    if (!pixel_data) 
        paletter_error(stbi_failure_reason());

    Color *color_list = read_palette_file(argv[2]);
    if (!color_list)
        paletter_error("Unable to read palette file");

    apply_palette(pixel_data, width, height, color_list);

    // Going to implement different and user-requested formats
    // and filenames for output
    stbi_write_png("res.png", width, height, 4, pixel_data, width * 4);

    sb_free(color_list);
    free(pixel_data);
    return 0;
}

void paletter_error(const char *errorstring)
{
    fprintf(stderr, "Error: %s\n", errorstring);
    exit(1);
}