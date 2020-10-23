#include <stdio.h>
#include <cs50.h>
#include <math.h>

/* Function counts the minimum number of coins needed to make 'change' value
** that it takes as argument, and then return this number
*/

int count_coins(float change)
{
    int coins = 0;

    // Rounds float value to integer
    int cents = round(change * 100);

    /*ach step of the loop extracts the biggest number of cents possible (25, 10, 5 or 1)
    **incrementing number of coins by 1
    */
    while (cents > 0)
    {
        if (cents >= 25)
        {
            cents -= 25;
        }
        else if ((cents < 25) && (cents >= 10))
        {
            cents -= 10;
        }
        else if ((cents < 10) && (cents >= 5))
        {
            cents -= 5;
        }
        else if ((cents < 5) && (cents >= 1))
        {
            cents -= 1;
        }
        coins++;
    }

    return coins;
}

int main(void)
{
    float change = 0.0;

    //Asking user to input change value
    do
    {
        change = get_float("Change owed: ");
    }
    while (change < 0.0);

    //Calling function to get number of coins needed.
    int coins = count_coins(change);

    printf("%d\n", coins);
    return 0;
}