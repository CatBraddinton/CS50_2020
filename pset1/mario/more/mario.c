#include <stdio.h>
#include <cs50.h>

/*This function is used to print hashes to screen.
** Function argument is a number of hashes it needs to print.
*/

void print_hashes(int i)
{
    char hash = '#';

    for (int hashes = 0; hashes < i; hashes++)
    {
        printf("%c", hash);
    }
}

int main(void)
{
    int height;
    char space = ' ';

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

        //Calling function to print specified number of hashes, creating left side of the pyramid
        print_hashes(i);

        //Printing two spaces to divide pyramid
        printf("  ");

        //Calling function to print specified number of hashes, creating right side of the pyramid
        print_hashes(i);

        printf("\n");
    }
    return 0;
}