// This program encrypts plain text using a key given as a command line argument. It passes through punctuation and numbers
// unchanged.

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Please enter one non-negative integer.\n");
        return 1;
    }

    // Variables
    int k = atoi(argv[1]);
    int cipher;
    string text = get_string("plaintext: ");
    int n = strlen(text);

    // Start printing
    printf("ciphertext: ");

    for (int i = 0; i < n; i++)
    {
        if (isalpha(text[i]))
        {
            // This code will convert ASCII values down to an alphabetical index starting at 0, apply the key, wraparound from 'z'
            // back to 'a', and reconvert back to ASCII to print. Maintains case sensitivity.
            if (isupper(text[i]))
            {
                text[i] = text[i] - 65;
                cipher = text[i] + k % 26;
                if (cipher > 25)
                {
                    cipher = cipher - 26;
                }
                cipher = cipher + 65;
                printf("%c", cipher);
            }
            else if (islower(text[i]))
            {
                text[i] = text[i] - 97;
                cipher = text[i] + k % 26;
                if (cipher > 25)
                {
                    cipher = cipher - 26;
                }
                cipher = cipher + 97;
                printf("%c", cipher);
            }
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
