#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int validate_key(string key)
{
    int length = strlen(key);
    if (length != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 0;
    }
    for (int i = 0; i < length; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 0;
        }
    }

    char c_key[length + 1];
    for (int i = 0; i < length; i++)
    {
        if (isupper(key[i]))
        {
            c_key[i] = key[i];
        }
        else if (islower(key[i]))
        {
            c_key[i] = toupper(key[i]);
        }
    }

    char temp = '\0';
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - 1; j++)
        {
            if (c_key[j] > c_key[j + 1])
            {
                temp = c_key[j];
                c_key[j] = c_key[j + 1];
                c_key[j + 1] = temp;
            }
        }
    }

    int res = 0;
    for (int i = 0; i < length - 1; i++)
    {
        res = c_key[i + 1] - c_key[i];
        if (res != 1)
        {
            printf("Key must not contain repeated characters.\n");
            return 0;
        }
    }
    return 1;
}

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    int validation_return = validate_key(argv[1]);
    if (validation_return != 1)
    {
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    int str_len = strlen(plaintext);
    char ciphertext[str_len + 1];

    int pos = 0;
    for (int i = 0; i < str_len; i++)
    {
        if (isupper(plaintext[i]))
        {
            pos = 25 - ('Z' - plaintext[i]);
            ciphertext[i] = toupper(argv[1][pos]);
        }
        else if (islower(plaintext[i]))
        {
            pos = 25 - ('z' - plaintext[i]);
            ciphertext[i] = tolower(argv[1][pos]);
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[str_len] = '\0';
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}