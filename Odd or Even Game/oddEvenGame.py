import random
chose = int(input("Type 1-Odd or 2-Even: "))
number = int(input("Type your number (between 0 or 5: "))

pcnumber = random.randint(0, 5)

result = number + pcnumber

if result % 2 == 0 and chose == 1:
    print(f"You selected {chose}")
    print(f"My number: {pcnumber} and your number: {number}")
    print("I won! Try again!")
elif result % 2 == 0 and chose == 2:
    print(f"You selected {chose}")
    print(f"My number: {pcnumber} and your number: {number}")
    print("You won! Well done!")
elif result % 2 == 1 and chose == 1:
    print(f"You selected {chose}")
    print(f"My number: {pcnumber} and your number: {number}")
    print("I won! Try again!")
else:
    print(f"You selected {chose}")
    print(f"My number: {pcnumber} and your number: {number}")
    print("You won! Well done!")
