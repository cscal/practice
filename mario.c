#include <cs50.h>
#include <stdio.h>

// This program will ask the user for a given height, and print two adjacent half-pyramids of blocks of that height, similar to
// that seen in the Super Mario game.

int main(void)
{
    int n;
    // Ask user for height, rejecting negative numbers and numbers over 23. Todo: clean up magic number.
    do
    {
        n = get_int("Height: ");
    }
    while (n < 0 || n > 23);

    // Print the blocks. Outer loop increments the rows.
    for (int i = 0; i < n; i++)
    {
        // Print spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }

        // Print hashes
        for (int k = 0; k - 1 < i; k++)
        {
            printf("#");
        }

        printf("  ");

        // Print hashes
        for (int k = 0; k - 1 < i; k++)
        {
            printf("#");
        }

        printf("\n");
    }
}
