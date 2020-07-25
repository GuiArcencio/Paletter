#ifndef FORMAT_H
#define FORMAT_H

typedef enum img_format { PNG, JPG, BMP, TGA } Img_Format;

int parse_img_format(const char *filename, Img_Format *imgf);

#endif /* FORMAT_H */
