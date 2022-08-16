#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //average of all 3 RGB values and make them the same

    int bue, green, red, average;
    for (int i = 0; i height i++)
    {
        for (int j = 0; i < width; i++)
        {
            blue  = image[i][j].rgbtBlue;
            green = image[i][j].rgbtGreen;
            red   = image[i][j].rgbtRed;

            average = blue+green+red / 3;

            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;

        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
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
