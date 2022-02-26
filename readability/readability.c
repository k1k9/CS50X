#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int colemanliau_index(string text);

int main(void)
{
    // Getting input from user
    string text = get_string("Text: ");
    int cl_index = colemanliau_index(text);

    if (cl_index < 1)
    {
        printf("Before Grade 1");
    }
    else if (cl_index >= 16)
    {
        printf("Grade 16+");
    }
    else
    {
        printf("Grade %i", cl_index);
    }

    printf("\n");
    return 0;
}

/*
* Return how much is letters in given text
*/
int colemanliau_index(string text)
{
    int letters = 0;
    int words = 0;
    int sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Check for letters
        if (isalpha(text[i]))
        {
            letters++;
        }
        // Check for words
        else if (text[i] == 32)
        {
            words++;
        }
        // Check for sentence
        else if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentences++;
        }
    }

    // Coleman-Liau Index
    words++;
    float l = ((float) letters / words) * 100;
    float s = ((float) sentences / words) * 100;
    int index = round((0.0588 * l) - (0.296 * s) - 15.8);
    return index;
}