#include <math.h>

#include "helpers.h"

#define COLORS 3.0
#define RGBTMAX 255

// calculate the average pixel value
RGBTRIPLE grayscale_pixel(int height, int width, RGBTRIPLE image[height][width], int x, int y)
{
    // calculate the average pixel value
    int average = round((image[x][y].rgbtBlue + image[x][y].rgbtGreen + image[x][y].rgbtRed) / COLORS);

    RGBTRIPLE triple;
    triple.rgbtBlue = average;
    triple.rgbtGreen = average;
    triple.rgbtRed = average;

    return triple;
}

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = grayscale_pixel(height, width, image, i, j);
        }
    }
    return;
}

// calculate the average pixel value
RGBTRIPLE sepia_pixel(int height, int width, RGBTRIPLE image[height][width], int x, int y)
{
    // calculate the average pixel value

    int red = round(0.393 * image[x][y].rgbtRed + 0.769 * image[x][y].rgbtGreen + 0.189 * image[x][y].rgbtBlue);
    if (red > RGBTMAX)
    {
        red = RGBTMAX;
    }
    int green = round(0.349 * image[x][y].rgbtRed + 0.686 * image[x][y].rgbtGreen + 0.168 * image[x][y].rgbtBlue);
    if (green > RGBTMAX)
    {
        green = RGBTMAX;
    }
    int blue = round(0.272 * image[x][y].rgbtRed + 0.534 * image[x][y].rgbtGreen + 0.131 * image[x][y].rgbtBlue);
    if (blue > RGBTMAX)
    {
        blue = RGBTMAX;
    }

    RGBTRIPLE sepia;
    sepia.rgbtRed = red;
    sepia.rgbtGreen = green;
    sepia.rgbtBlue = blue;

    return sepia;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = sepia_pixel(height, width, image, i, j);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
