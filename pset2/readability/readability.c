#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string str = get_string("Text: ");

    int letters = 0;
    int words = 1;
    int sentences = 0;

    for (int i = 0, n = strlen(str); i < n; i++)
    {
        if (isalpha(str[i]))
        {
            letters++;
        }
        else if (str[i] == ' ')
        {
            words++;
        }
        else if ((str[i] == '.') || (str[i] == '!') || (str[i] == '?'))
        {
            sentences++;
        }
    }

    //printf("letters: %d\n", letters);
    //printf("words = %d\n", words);
    //printf("sentences = %d\n", sentences);


    double index = 0.0588 * (letters * 100.0 / words) - 0.296 * (sentences * 100.0 / words) - 15.8;
    //printf("index = %d\n", (int) round(index));

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", (int)round(index));
    }

    return 0;
}