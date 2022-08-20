# TODO
from cs50 import get_string


def main():
    text = get_string("text: ")

    letters = count_letters(text)

    words = count_words(text)

    sentences = count_sentences(text)

    # calculating the grade
    calculate = 0.0588 * letters / words * 100 - 0.296 * sentences / words * 100 - 15.8

    if calculate >= 16:
        print("Grade 16+")
    elif calculate < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {round(calculate)}")


def count_letters(word):
    count = 0

    for i in word:
        if i.isalpha():
            count += 1

    return count


def count_words(word):
    words = 1

    for i in word:
        if i == " ":
            words += 1

    return words


def count_sentences(word):
    sentences = 0

    for i in word:
        if i == "?" or i == "!" or i == ".":
            sentences += 1

    return sentences


main()