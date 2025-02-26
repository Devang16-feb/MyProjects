# We all have played snake, water gun game in our childhood. If you haven’t, google the 
# rules of this game and write a python program capable of playing this game with the 
# user. 

import random
'''
1 for snake
-1 for water
0 for gun
'''

#computer = -1 #Here we have to generate random number 
computer = random.choice([-1,1,0])
youstr = input("Enter your choice: ")
youDict = {"s":1, "w":-1, "g":0}
reverseDict = {1: "Snake", -1: "Water", 0: "Gun"}

younum = youDict[youstr]

print(f"You choose {reverseDict[younum]}\nComputer choose {reverseDict[computer]}")

if(computer == younum):
    print("Draw")
else:
    if(computer == -1 and younum == 1):
        print("You win")
    elif(computer == -1 and younum == 0):
        print("You lose")
    elif(computer == 1 and younum == 0):
        print("You win")
    elif(computer == 1 and younum == -1):
        print("You lose")
    elif(computer == 0 and younum == 1):
        print("You lose")
    elif(computer == 0 and younum == -1):
        print("You win")
    else:
        print("someting went wrong")
      
      
#short Cut :
  
# if(computer-younum == -1 or computer-younum == 2):
#     print("You loose")
# else:
#     print("You win")