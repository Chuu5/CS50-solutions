#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool isDigit(string parameter);
char encrypt(char text, int timeToRun);

int main(int argc, string argv[])
{

   if (argc > 2 || argc == 1) {
       printf("Usage: ./caesar key\n");
       return 1;
   }

   if (isDigit(argv[1]) == false) {
       printf("Usage: ./caesar key\n");
       return 1;
   }

    int argument = atoi(argv[1]);
    string planText = get_string("plantext: ");

    for(int i = 0; i < strlen(planText); i++) {
        if (i == 0) {
            printf("ciphertext: ");
        }
        encrypt((char)planText[i], argument);
    }
    printf("\n");
}



bool isDigit(string digits) {
    for(int i = 0; i < strlen(digits); i++) {
        if (isdigit(digits[i])) {
        } else {
            return false;
        }
    }
    return true;
}


char encrypt(char text, int timeToRun) {
    if(isalpha(text) != 0) {
     return  printf("%c", text + timeToRun);
    } else {
        return text;
    }
}

