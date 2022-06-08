#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string get_name = get_string("What's your name? ");
    printf("hello, %s\n", get_name);
}