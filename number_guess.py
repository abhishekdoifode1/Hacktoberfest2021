"""Fun short script implementing a number guessing game

    Script usage:
        $ python3 -m number_guess.py [low] [high]

        low and high are optional, they determine what the minimum
        number and maximum number are. If not specified,
        they're 1 and 50 respectively.

        $ python3 -m number_guess.py
        Guess #1 : 20
        Guess higher!
        Guess #2 : 30
        Guess higher!
        Guess #3 : 40
        Guess lower!
        Guess #4 : 35
        Guess lower!
        Guess #5 : 32
        You win!

    Module usage:
        >>> import number_guess as ng
        >>> ng.guess_the_number()

        Guess #1 : 20
        Guess lower!
        Guess #2 : 5
        Guess lower!
        Guess #3 : 2
        Guess higher!
        You failed! The correct number was 4
"""

import random


def _find_factors(number: int) -> list:
    """Get all factors of a given number

    :param number: The number we're finding the factor of
    :type number: int
    :returns: A list of all the factors.
    :rtype: list"""

    factors = []

    for digit in range(1, number//2 + 1):
        if number % digit == 0:
            factors.append(digit)

    factors.append(number)

    return factors


def guess_the_number(lowest_guess: int = 1, highest_guess: int = 10, *,
                     guess_limit: int = 3, is_basic: bool = False) -> None:
    """Starts the guess the number prompting

    :param lowest_guess: Minimum possible number
    :type lowest_guess: int
    :param highest_guess: Maximum possible number
    :type highest_guess: int
    :param guess_limit: Maximum number of guesses one gets.
    :type guess_limit: int
    :param is_basic: if True, hints are disabled.
    :type is_basic: bool
    :rtype: None"""

    correct_number = random.randint(lowest_guess, highest_guess)

    if is_basic:
        hint = ""
    else:
        hint = random.choice(["Higher Lower", "Factor"])

    # TODO: Add more hint possibilites

    for current_guess in range(1, guess_limit+1):
        guess = int(input(f"Guess #{current_guess} : "))

        if guess == correct_number:
            print("You win!")
            break
        elif hint == "Higher Lower":
            if guess > correct_number:
                print("Guess lower!")
            else:
                print("Guess higher!")
        elif hint == "Factor":
            print("This number has "
                  f"{random.choice(_find_factors(correct_number))} "
                  "as a factor!")
    else:
        print(f"You failed! The correct number was {correct_number}")

    # BUG: Last hint displays even after running out of tries
    # TODO: Limit the correct factor hint


if __name__ == "__main__":
    import sys

    if sys.argv[1:]:
        try:
            low, high = (int(num) for num in sys.argv[1:])
        except ValueError:
            print('Invalid inputs!')
    else:
        low, high = 1, 50

    guess_the_number(low, high, guess_limit=5)
