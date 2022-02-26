#include <cs50.h>
#include <stdio.h>

int main(void)
{

    // Getting input from user
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Drawing
    for (int i = 0; i < height; i++)
    {

        // Right side triangle
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }

        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }

        printf("  ");

        // Left side triangle
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}