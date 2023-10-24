"""
Author: sanam kandar
Project: Mad libs generator ("Story: The golden egg!")
"""

print("\t\t\t\t\t\t\t\t♦♦♦♦♦ MAD LIBS GENERATOR ♦♦♦♦♦♦\n\t\t\t\t\t\t\t\t Put words for funny story")

def story():

    cloth_merchant = input("write a profession: ").lower()
    wife = input("write your one relative: ")
    two =  input("write a number: ").lower()
    hen = input("write a poultry animal: ").lower()
    golden = input("write your favourite colour: ").lower()
    rich = input("when you have lots of money: ").lower()
    kill = input("what you like to do in your free time: ").lower()
    pauper = input("write what you want to be: ").lower()
    foolish = input("what you like to make people: ").lower()
    neck = input("write any body part: ").lower()

    print(f"\nOnce upon a time, there lived a {cloth_merchant} in a village with his {wife} and {two} children. They were indeed quite well-off. They had a beautiful {hen} which laid an egg every day. It was not an ordinary egg, rather, a {golden} egg. But the man was not satisfied with what he used to get daily. He was a get {rich}-trice kind of a person. The man wanted to get all the {golden} eggs from his {hen} at one single go. So, one day he thought hard and at last clicked upon a plan. He decided to {kill} the {hen} and get all the eggs together. So, the next day when the {hen} laid a {golden} egg, the man caught hold of it, took a sharp knife, chopped off its {neck} and cut its body open. There was nothing but blood all around & no trace of any egg at all. He was highly grieved because now he would not get even one single egg. His life was going on smoothly with one egg a day but now, he himself made his life miserable. The outcome of his greed was that he started becoming poorer & poorer day by day and ultimately became a {pauper}. How jinxed and how much {foolish} he was.")
story()
