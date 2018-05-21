// Cash. This program uses a greedy algorithm to accept a float value (change owed) and output the smallest number of coins
// required to give change back.

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Ask cashier for amount of change needed
    float n;
    do
    {
        n = get_float("Change: ");
    }
    while (n <= 0);

    // Convert dollars to cents
    n = n * 100;

    // Round off floating point imprecision
    n = round(n);

    // The greedy algorithm. Denominations are in quarters, dimes, nickels, and pennies.
    int coins = 0;
    while (n - 25 >= 0)
    {
        n = n - 25;
        coins++;
    }
    while (n - 10 >= 0)
    {
        n = n - 10;
        coins++;
    }
    while (n - 5 >= 0)
    {
        n = n - 5;
        coins++;
    }
    while (n - 1 >= 0)
    {
        n = n - 1;
        coins++;
    }

    // Print out number of coins
    printf("%i\n", coins);

}
