/****************************************************************************
 * resize.c
 *
 * Computer Science 50
 * Problem Set 4
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: resize factor infile outfile\n");
        return 1;
    }

    // remember filenames
    int factor = atoi(argv[1]); //string to int
    char* infile = argv[2];
    char* outfile = argv[3];

    //check resize factor
    if ((factor < 1) || (factor > 100))
    {
        printf("Resize factor must be between 1-100\n");
        return 2;
    }

    // open input file
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 3;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 5;
    }

    // create variables for old height and width
    int oldwidth = bi.biWidth;
    int oldheight = bi.biHeight;

    // create variables for new height and width
    int newwidth = bi.biWidth * factor;
    int newheight = bi.biHeight * factor;

    // determine padding
    int oldpadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int newpadding = (4 - (newwidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // update length
    int oldlength = (oldwidth * 3) + oldpadding;//why oldwith*3

    // update image size
    bi.biSizeImage = abs(newheight) * (newwidth * sizeof(RGBTRIPLE) + newpadding);

    // update file size
    bf.bfSize = bf.bfOffBits + bi.biSizeImage;

    // update height and width
    bi.biWidth = newwidth;
    bi.biHeight = newheight;


    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0; i < abs(oldheight); i++)
    {
        //iterate factor no. of times
        for (int p = 0; p < factor; p++)
        {
            //move back cursor
            fseek(inptr, 54 + oldlength * i , SEEK_SET);

            // iterate over pixels in scanline
            for (int j = 0; j < oldwidth; j++)
            {

                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RGB triple to outfile
                for (int z  = 0; z < factor; z++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }

            }

            // add new padding
            for (int k = 0; k < newpadding; k++)
            {
                fputc(0x00, outptr);
            }

        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}