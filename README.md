# Paletter
#### A little pet project born out of quarantine boredom.

Do you have a nice picture and a cool palette and want to mix them up? Your solution is here! Use Paletter to make all colors in your image turn into one of the colors in the palette, minimizing their "color difference".

### Compiling
With [gcc](https://gcc.gnu.org/) installed on your machine, simply run:
```
make all
```
in the repository's root directory.

### Usage
To use Paletter, you will need an image file and a [CSV](https://en.wikipedia.org/wiki/Comma-separated_values) file that contains the hexcode of each color in your palette, separated by commas. Then, run:
```
./paletter <path-to-image-file> <path-to-csv-file> <output-file>
```
Or, if you use Windows, you might have to rename the file "paletter.exe", and then run:
```
paletter.exe <path-to-image-file> <path-to-csv-file> <output-file>
```
There are four supported output formats:
- PNG (.png)
- JPG (.jpg, .jpeg, .jpe, .jif, .jfif, .jfi)
- BMP (.bmp, .dib)
- TGA (.tga, .targa, .tpic)

### Example
Using the following palette:
```
54478c,2c699a,048ba8,0db39e,16db93,83e377,b9e769,efea5a,f1c453,f29e4c
```
The original and *paletted* pictures are seen below:

|<img src="/examples/original.jpg" width="600">|<img src="/examples/paletted.png" width="600">|
|:-:|:-:|

I've put a number of palettes you can play with in the `examples/palettes` folder.

### Libraries
I'm using three of Sean Barrett's amazing [single-file libraries](https://github.com/nothings/stb) for image manipulation and dynamic arrays. Go check them out!
