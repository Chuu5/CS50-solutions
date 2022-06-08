#include <cs50.h>
#include <stdio.h>



int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1  || height > 8);


    for (int i = 0; i < height; i++)
        // Making lines Here
    {
        for (int spaces = height - i - 1; spaces > 0; spaces--)
        {
            // Making spaces here
            printf(" ");
        }
        printf("#");
        for (int j = 0; j < i; j++)
        {
            // Making Columns Here
            printf("#");
        }
        printf("\n");
    }

}