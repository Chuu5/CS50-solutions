#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    // TODO
    int cents;
    do
    {
        cents = get_int("How many cents you owed? ");
    }
    while (cents < 1);

    return cents;
}

int calculate_quarters(int cents)
{
    // TODO
    int n1 = cents / 25;
    printf("Irá receber moedas de 25: %i\n", n1);

    return cents / 25;
}

int calculate_dimes(int cents)
{
    // TODO
    int n2 = cents / 10;
    printf("Irá receber moedas de 10: %i\n", n2);
    return cents / 10;
}

int calculate_nickels(int cents)
{
    // TODO
    int n3 = cents / 5;
    printf("Irá receber moedas de 5: %i\n", n3);
    return cents / 5;
}

int calculate_pennies(int cents)
{
    // TODO
    int n4 = cents / 1;
    printf("Irá receber moedas de 1: %i\n", n4);
    return cents / 1;
}
