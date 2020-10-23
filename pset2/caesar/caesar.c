#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void print_error_message(void)
{
    printf("Usage: ./caesar key\n");
}

int check_key(string str)
{
    for (int i = 0, n = strlen(str); i < n; i++)
    {
        if (!isdigit(str[i]))
        {
            return 0;
        }
    }

    return 1;
}

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        print_error_message();
        return 1;
    }

    long key = 0;
    if (check_key(argv[1]))
    {
        key = atol(argv[1]);
    }
    else
    {
        print_error_message();
        return 1;
    }

    if (key > 26)
    {
        key %= 26;
    }
    string plaintext = get_string("plaintext: ");

    int size = strlen(plaintext);
    char ciphertext[size + 1];
    char c = '\0';
    int n = 0;
    int encrypt = 0;

    for (int i = 0; i < size; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (islower(plaintext[i]))
            {
                n = 25 - ('z' - plaintext[i]);
                encrypt = (n + key) % 26;
                c = 'a' + encrypt;

            }
            else if (isupper(plaintext[i]))
            {
                n = 25 - ('Z' - plaintext[i]);
                encrypt = (n + key) % 26;
                c = 'A' + encrypt;
            }
            ciphertext[i] = c;
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    ciphertext[size] = '\0';

    printf("ciphertext: %s\n", ciphertext);

    return 0;
}