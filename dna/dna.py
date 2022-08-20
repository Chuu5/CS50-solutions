import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        return 1

    # TODO: Read database file into a variable
    total = []
    datas = []
    persons = dict()

    database = open(f"{sys.argv[1]}")

    reader_data = csv.reader(database)
    for row in reader_data:

        for i in range(len(row)):

            if i != 0:
                datas.append(row[i])

        break

    for row in reader_data:
        name = row[0]
        sequences = []
        for i in range(len(row)):
            if i != 0:
                sequences.append(row[i])

        persons[name] = sequences

    # TODO: Read DNA sequence file into a variable
    dna = open(f"{sys.argv[2]}")
    reader_dna = dna.read()

    for i in datas:
        total.append(longest_match(reader_dna, i))

    # TODO: Find longest match of each STR in DNA sequence

    # TODO: Check database for matching profiles
    for person in persons:
        count = 0

        for i in range(len(total)):

            # converting the number in the person sequence to a integer
            n = int(persons[person][i])

            if n == total[i]:
                count += 1

            if count == len(total):
                print(person)
                return

    print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
