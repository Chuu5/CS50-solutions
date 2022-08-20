# TODO
from cs50 import get_float


def main():

    while True:
        owed = get_float("Change owed: ")
        if owed > 0:
            break

    quarters = calc_quarters(owed)
    owed -= quarters * 0.25
    # rounding to a 2 decimal number
    owed = round(owed, 2)

    dimes = calc_dimes(owed)
    owed -= dimes * 0.10
    owed = round(owed, 2)

    nickel = calc_nickel(owed)
    owed -= nickel * 0.05
    owed = round(owed, 2)

    pennies = calc_pennies(owed)
    owed -= pennies * 0.01
    owed = round(owed, 2)

    #
    output = round(quarters + dimes + nickel + pennies)

    print(output)


def calc_quarters(owd):
    return owd // 0.25


def calc_dimes(owd):
    return owd // 0.10


def calc_nickel(owd):
    return owd // 0.05


def calc_pennies(owd):
    return owd // 0.01


main()