#include <stdio.h>
#include <cs50.h>

int get_first_digit(long card_number)
{
    int first_digit = 0;

    while (card_number > 10)
    {
        card_number /= 10;
    }
    first_digit = card_number;

    return first_digit;
}

int get_second_digit(long card_number)
{
    int second_digit = 0;

    while (card_number > 100)
    {
        card_number /= 10;
    }
    second_digit = card_number % 10;

    return second_digit;
}


void print_card_name(long card_number)
{
    int digits = 0;
    int first_digit = 0;
    int second_digit = 0;
    long card_number_copy = card_number;

    while (card_number_copy > 0)
    {
        card_number_copy /= 10;
        digits++;
    }
    //printf("digits = %d\n", digits);

    if ((digits == 13) || (digits == 15) || (digits == 16))
    {
        first_digit = get_first_digit(card_number);
        //printf("first_digit = %d\n", first_digit);

        second_digit = get_second_digit(card_number);
        //printf("second digit = %d\n", second_digit);

    }
    else
    {
        printf("INVALID\n");
        return ;
    }
    if (digits == 15)
    {
        if (first_digit == 3)
        {
            if ((second_digit == 4) || (second_digit == 7))
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (digits == 16 && first_digit == 5)
    {
        if ((second_digit == 1) || (second_digit == 2) ||
            (second_digit == 3) || (second_digit == 4) || (second_digit == 5))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (first_digit == 4 && ((digits == 13) || (digits == 16)))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

void check_card(long card_number)
{
    int sum = 0;
    int number = 0;
    long card_number_copy = card_number;

    while (card_number_copy > 0)
    {
        //printf("%ld\n", card_number_copy);
        card_number_copy /= 10;
        number = card_number_copy % 10 * 2;
        while (number >= 10)
        {
            sum += number % 10;
            number /= 10;
        }
        sum += number;
        card_number_copy /= 10;
    }
    //printf("sum = %d\n", sum);

    card_number_copy = card_number;

    while (card_number_copy > 0)
    {
        sum += card_number_copy % 10;
        card_number_copy /= 100;
    }

    //printf("check_sum = %d\n", sum);

    if ((sum % 10) != 0)
    {
        printf("INVALID\n");
        return ;
    }

    print_card_name(card_number);
}

int main(void)
{
    long card_number;

    do
    {
        card_number = get_long("Number: ");
    }
    while (card_number <= 0);

    check_card(card_number);
    return 0;
}