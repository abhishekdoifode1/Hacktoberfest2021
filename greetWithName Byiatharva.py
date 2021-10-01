#Enter your name and it will greet you according to the time.
import datetime

def greeting(input_word):
    now = datetime.datetime.now()
    if now.hour < 12:
        print("Good morning, " + input_word)
    elif now.hour < 18:
        print("Good afternoon, " + input_word)
    else:
        print("Good evening, " + input_word)

def main():
    input_word = input("Enter your name: ")
    greeting(input_word)

main()
        