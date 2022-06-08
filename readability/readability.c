#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int letter(string text);
int count_words(string text);
int count_sentences(string text);


int main(void)
{
    string text = get_string("text: ");
    int letters = letter(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    printf("%i letters\n", letters);
    printf("%i words\n", words);
    printf("%i sentences\n", sentences);

    float calculateGrade = 0.0588 * letters / words * 100 - 0.296 * sentences / words * 100 - 15.8;

    if(calculateGrade >= 16) {
        printf("Grade 16+\n");
    } else if (calculateGrade < 1) {
        printf("Before Grade 1\n");
    } else {
        printf("Grade %i\n", (int) round(calculateGrade));
    }

}



int letter(string text) {
    int count_letters = 0;
    for(int i = 0; i < strlen(text); i++) {
        if(text[i] >= 'a' && text[i] <= 'z') {
            count_letters += 1;
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            count_letters += 1;
        }
    }
    return count_letters;

}

int count_words(string text) {
    int words = 1;
    for(int i = 0; i < strlen(text); i++) {
        if(text[i] == ' ') {
            words += 1;
        }
    }
    return words;
}

int count_sentences(string text) {
    int sentences = 0;
    for(int i = 0; i < strlen(text); i++) {
        if((int) text[i] == 33 || (int) text[i] == 46 || (int) text[i] == 63) {
            sentences += 1;
        }
    }
    return sentences;
}