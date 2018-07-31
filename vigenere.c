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
        printf("Please give a valid key composed of alphabetical characters.\n");
        return 1;
    }

    int j;
    string k = argv[1];
    int o = strlen(k);
    for (j = 0; j < o; j++)
    {
        // Checks for valid key, then converts key values to alphabetical index
        if (isalpha(k[j]) == false)
        {
            printf("Please give a valid key composed of alphabetical characters.\n");
            return 1;
        }
        else if (isupper(k[j]))
        {
            k[j] = k[j] - 65;
        }
        else if (islower(k[j]))
        {
            k[j] = k[j] - 97;
        }
    }

    j = 0;
    int cipher;
    string text = get_string("plaintext: ");
    int n = strlen(text);

    // Start printing
    printf("ciphertext: ");

// This code will convert ASCII values down to an alphabetical index starting at 0, wraparound the key if necessary,
// apply the key, wraparound input text from 'z' back to 'a', and reconvert back to ASCII to print. Maintains case sensitivity.
    for (int i = 0; i < n; i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                text[i] = text[i] - 65;
                if (j >= o)
                {
                    j = j - o;
                }
                cipher = (text[i] + k[j]) % 26;
                j++;
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
                if (j >= o)
                {
                    j = j - o;
                }
                cipher = (text[i] + k[j]) % 26;
                j++;
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
