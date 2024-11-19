# Guessing number game

import random 

count = 0 
print (" Let's play a game. You have to guess the number the computer thinks it is within six times. \
If you're ready, press Enter. ")
input ()

goal = random.randint (1, 100)
print("Okay, now that I have a number, let's take a guess")

while count < 6 :
    guess = input ("What number do you expect?")
    guess = int(guess)
      
    count += 1
  
    if guess == goal: 
        break 
    elif guess > goal: 
        print ("It's a lower number…")
    else: 
        print("It's a higher number…")

if guess == goal : 
    count = str(count) 
    print ("Right ! ") 
else: 
    goal= str(goal) 
    print("Oops...the number I thought was\t"  + goal + ".") 

print("Exit the program")
