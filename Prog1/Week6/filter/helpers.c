/*******************************************
* helpers.c
*
* Steven Kooi
* Programmeren 1
*
* - contains the implementations of the functions declared in helpers.h
*
* last edit: 18-10-2022
*********************************************/

#include "helpers.h"
#include <math.h>
//#include <stdio.h>

/*
 * Function:  grayscale_pixel
 * --------------------------
 * converts the rgb values of a pixel to the average value of the three colors
 *
 *  image[heigth][width]: RGBTRIPLE image with its heigth and width
 *  x: horizontal index of pixel to convert
 *  y: vertical index of pixel to convert
 *
 *  returns: RGBTRIPLE type triple with averaged rgb values
 */
RGBTRIPLE grayscale_pixel(int height, int width, RGBTRIPLE image[height][width],
                          int x, int y)
{
    // set each color value to the average rgb value
    RGBTRIPLE triple;
    int average_rgb_value = round((image[x][y].rgbtRed + image[x][y].rgbtBlue +
                                   image[x][y].rgbtGreen) / 3.00);
    triple.rgbtBlue = average_rgb_value;
    triple.rgbtGreen = average_rgb_value;
    triple.rgbtRed = average_rgb_value;
    return triple;
}

/*
 * Function:  grayscale
 * --------------------
 * converts a RGBTRIPLE image to grayscale by looping over each pixel and calling
 * grayscale_pixel() on it
 *
 *  image[heigth][width]: RGBTRIPLE image with its heigth and width
 *
 *  returns: image[height][width] in grayscale
 */
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // loop over height
    for (int i = 0; i < height; i++)
    {
        // loop over width
        for (int j = 0; j < width; j++)
        {
            image[i][j] = grayscale_pixel(height, width, image, i, j);
        }
    }
    return;
}


/*
 * Function:  limit
 * ----------------
 * limits the maximum value of an int to 255
 *
 *  value: an int
 *
 *  returns: int value with upperlimit 255
 */
int limit(int value)
{
    if (value > 255)
    {
        value = 255;
    }
    return value;
}

/*
 * Function:  sepia_pixel
 * ----------------------
 * converts the rgb values of a pixel to sepia by using an algorithm to
 * calculate
 *
 *  image[heigth][width]: RGBTRIPLE image with its heigth and width
 *  x: horizontal index of pixel to convert
 *  y: vertical index of pixel to convert
 *
 *  returns: RGBTRIPLE type triple with rgb values converted to sepia
 */
RGBTRIPLE sepia_pixel(int height, int width, RGBTRIPLE image[height][width],
                      int x, int y)
{
    // get original pixel values
    RGBTRIPLE triple;
    int originalRed = image[x][y].rgbtRed;
    int originalGreen = image[x][y].rgbtGreen;
    int originalBlue = image[x][y].rgbtBlue;

    // calculate sepia color values with an upperlimit of 255
    triple.rgbtBlue = limit(round(.272 * originalRed + .534 * originalGreen +
                                  .131 * originalBlue));
    triple.rgbtGreen = limit(round(.349 * originalRed + .686 * originalGreen +
                                   .168 * originalBlue));
    triple.rgbtRed = limit(round(.393 * originalRed + .769 * originalGreen +
                                 .189 * originalBlue));
    return triple;
}

/*
 * Function:  sepia
 * ----------------
 * converts a RGBTRIPLE image to sepia by looping over each pixel and calling
 * sepia_pixel() on it
 *
 *  image[heigth][width]: RGBTRIPLE image with its heigth and width
 *
 *  returns: image[height][width] in sepia
 */
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // loop over pixels in image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = sepia_pixel(height, width, image, i, j);
        }
    }
    return;
}

/*
 * Function:  reflect
 * ------------------
 * reflects a RGBTRIPLE image horizontally by swapping a pixel with its opposite
 * on the same row
 *
 *  image[heigth][width]: RGBTRIPLE image with its heigth and width
 *
 *  returns: image[height][width] reflected horizontally
 */
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // loop over height
    for (int i = 0; i < height; i++)
    {
        // loop over half of width
        for (int j = 0; j < width / 2; j++)
        {
            // swap pixels opposite to each other in the image
            RGBTRIPLE placeholder = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = placeholder;
        }
    }
    return;
}

/*
 * Function:  blur_pixel
 * ---------------------
 * uses "box-blur" to convert the rgb values of a pixel to a blurred pixel by
 * averaging all neighboring pixels in a 3x3 box. Edge cases are ignored
 *
 *  image[heigth][width]: bitmap image with its heigth and width
 *  x: horizontal index of pixel to convert
 *  y: vertical index of pixel to convert
 *
 *  returns: RGBTRIPLE type triple with box-blurred rgb values
 */
RGBTRIPLE blur_pixel(int height, int width, RGBTRIPLE image[height][width],
                     int x, int y)
{
    // track the total rgb values surrounding the pixel
    int sum_of_blue_values = 0;
    int sum_of_red_values = 0;
    int sum_of_green_values = 0;
    float pixels_counted = 0.0;

    // loop 3x3 grid around pixel image[x][y]
    for (int i = x - 1; i <= x + 1; i++)
    {
        for (int j = y - 1; j <= y + 1; j++)
        {
            // ignore pixels outside the edge of the image
            int outside_image = i < 0 || i >= height || j < 0 || j >= width;
            if (!outside_image)
            {
                sum_of_blue_values += image[i][j].rgbtBlue;
                sum_of_red_values += image[i][j].rgbtRed;
                sum_of_green_values += image[i][j].rgbtGreen;
                pixels_counted++;
            }
        }
    }
    // average the rgb values and return
    RGBTRIPLE triple;
    triple.rgbtBlue = round(sum_of_blue_values / pixels_counted);
    triple.rgbtGreen = round(sum_of_green_values / pixels_counted);
    triple.rgbtRed = round(sum_of_red_values / pixels_counted);
    return triple;
}

/*
 * Function:  blur
 * ---------------
 * blurs a RGBTRIPLE image by making a copy of the image, looping over the
 * copy and calling blur_pixel() on its pixels. The blurred pixels are stored
 * back in the original image to not interfere with the calculation of
 * blur_pixel
 *
 *  image[heigth][width]: bitmap image with its heigth and width
 *
 *  returns: blurred version of image[heigth][width]
 */
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // copy the pixels in the image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // blur pixels calculated from the copy and store in image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = blur_pixel(height, width, copy, i, j);
        }
    }
    return;
}
