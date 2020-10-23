#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    char space = ' ';
    char hash = '#';

    //Asking user to input desired pyramid height
    do
    {
        height = get_int("Height: ");
    }
    while ((height < 1) || (height > 8));

    //Drawing pyramid using spaces and hashes

    for (int i = 1; i <= height; i++)
    {
        //Printing the leading spaces before hashes if height is more than 1
        for (int spaces = 0; spaces < height - i; spaces++)
        {
            printf("%c", space);
        }

        //Printing hashes after spaces
        for (int hashes = 0; hashes < i; hashes++)
        {
            printf("%c", hash);
        }
        printf("\n");


    }
    return 0;
}