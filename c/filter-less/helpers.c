#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //average of all 3 RGB values and make them the same

    float average;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;

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
    float originalRed, originalGreen, originalBlue;
    float sepiaRed, sepiaGreen, sepiaBlue;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            originalBlue  = image[i][j].rgbtBlue;
            originalGreen = image[i][j].rgbtGreen;
            originalRed   = image[i][j].rgbtRed;

            sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue;
            sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue;
            sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue;

            //values capped at 255 (most of the color)
            sepiaRed = sepiaRed > 255 ? 255 : sepiaRed;
            sepiaGreen = sepiaGreen > 255 ? 255 : sepiaGreen;
            sepiaBlue = sepiaBlue > 255 ? 255 : sepiaBlue;

            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            temp.rgbtBlue   = image[i][j].rgbtBlue;
            temp.rgbtGreen  = image[i][j].rgbtGreen;
            temp.rgbtRed    = image[i][j].rgbtRed;

            image[i][j] = image[i][width-j];
            image[i][width-j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    //copy image into temp variable, because the original pixels will change and therefor
    // effect future pixel calculations
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }



    int totalRed, totalGreen, totalBlue;
    int currentX, currentY;

    //counter changed depending how many pixels are valid i.e. on edge of image is 6
    float counter;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++) {
            totalRed = totalGreen = totalBlue = 0;
            currentX = currentY = 0;
            counter = 0;
            for (int x = -1; x < 2; x++) {
                for (int y = -1; y < 2; y++) {
                    currentX = i + x;
                    currentY = j + y;

                    //check for valid pixel i.e. is on the image
                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1)) {
                        continue;
                    }

                    totalRed += image[currentX][currentY].rgbtRed;
                    totalGreen += image[currentX][currentY].rgbtGreen;
                    totalBlue += image[currentX][currentY].rgbtBlue;

                    counter++;
                }

                temp[i][j].rgbtRed = round(totalRed / counter);
                temp[i][j].rgbtGreen = round(totalGreen / counter);
                temp[i][j].rgbtBlue = round(totalBlue / counter);
            }
        }
    }


    //copy temp into original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }

    return;
}
