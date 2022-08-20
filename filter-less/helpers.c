#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // loop em volta de todos os pixels da imagem
    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {
            int sum = image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen;
            int average = round(sum / 3.0);


            // Somando a media das 3 cores para setarmos a nova cor
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // loop em volta de todos os pixels da imagem
    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {
            int originalBlue = image[i][j].rgbtBlue;
            int originalGreen = image[i][j].rgbtGreen;
            int originalRed = image[i][j].rgbtRed;

            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // loop em volta de todos os pixels da imagem
    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width / 2; j++)
        {

            RGBTRIPLE tmp = image[i][j];
            // make a temporary variable to copy the pixel to swap with the last position

            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = tmp;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    // Criando uma copia do array original

    // loop em volta de todos os pixels da imagem
    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {

            copy[i][j] = image[i][j];

            int averageRed = copy[i][j].rgbtRed;
            int averageBlue = copy[i][j].rgbtBlue;
            int averageGreen = copy[i][j].rgbtGreen;
            float counter = 1.00;
            // fazendo um contador para contar quantos blocos foram somados na media, para ser dividido no final


            if (j - 1 >= 0)
            {

                averageRed += copy[i][j - 1].rgbtRed;
                averageGreen += copy[i][j - 1].rgbtGreen;
                averageBlue += copy[i][j - 1].rgbtBlue;

                counter++;
            }
            if (j + 1 <= width - 1)
            {
                copy[i][j + 1] = image[i][j + 1];

                averageRed += copy[i][j + 1].rgbtRed;
                averageGreen += copy[i][j + 1].rgbtGreen;
                averageBlue += copy[i][j + 1].rgbtBlue;

                counter++;
            }

            if (i - 1 >= 0)
            {

                averageRed += copy[i - 1][j].rgbtRed;
                averageGreen += copy[i - 1][j].rgbtGreen;
                averageBlue += copy[i - 1][j].rgbtBlue;

                counter++;
            }

            if (i + 1 <= height - 1)
            {
                copy[i + 1][j] = image[i + 1][j];

                averageRed += copy[i + 1][j].rgbtRed;
                averageGreen += copy[i + 1][j].rgbtGreen;
                averageBlue += copy[i + 1][j].rgbtBlue;

                counter++;
            }

            if (i + 1 <= height - 1 && j + 1 <= width - 1)
            {
                copy[i + 1][j + 1] = image[i + 1][j + 1];

                averageRed += copy[i + 1][j + 1].rgbtRed;
                averageGreen += copy[i + 1][j + 1].rgbtGreen;
                averageBlue += copy[i + 1][j + 1].rgbtBlue;

                counter++;
            }

            if (i - 1 >= 0 && j - 1 >= 0)
            {

                averageRed += copy[i - 1][j - 1].rgbtRed;
                averageGreen += copy[i - 1][j - 1].rgbtGreen;
                averageBlue += copy[i - 1][j - 1].rgbtBlue;

                counter++;
            }

            if (i - 1 >= 0 && j + 1 <= width - 1)
            {

                // copy[i - 1][j + 1] = image[i - 1][j + 1];

                averageRed += copy[i - 1][j + 1].rgbtRed;
                averageGreen += copy[i - 1][j + 1].rgbtGreen;
                averageBlue += copy[i - 1][j + 1].rgbtBlue;

                counter++;
            }

            if (i + 1 <= height - 1 && j - 1 >= 0)
            {
                // copy[i + 1][j - 1] = image[i + 1][j - 1];

                averageRed += copy[i + 1][j - 1].rgbtRed;
                averageGreen += copy[i + 1][j - 1].rgbtGreen;
                averageBlue += copy[i + 1][j - 1].rgbtBlue;

                counter++;
            }

            image[i][j].rgbtRed = round(averageRed / counter);
            image[i][j].rgbtGreen = round(averageGreen / counter);
            image[i][j].rgbtBlue = round(averageBlue / counter);
        }
    }
    return;
}

