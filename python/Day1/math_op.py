import math

choice = int(input("Enter 1 to add, 2 to subtract, 3 to square root, 4 to divide numbers: "))
if(choice == 1):
    a = int(input("Enter the first number: "))
    b = int(input("Enter the second number: "))
    print("The sum of two numebers is: {}".format(a+b))
elif(choice == 2):
    a = int(input("Enter the first number: "))
    b = int(input("Enter the second number: "))
    print("The subtraction of two numebers is: {}".format(a-b))
elif(choice == 3):
    a = int(input("Enter the first number: "))
    print("The square root of teh given number is: {:.2f}".format(math.sqrt(a)))
elif(choice == 4):
    a = int(input("Enter the first number: "))
    b = int(input("Enter the second number: "))
    if(b==0):
        print("Division by zero not possible!")
    else:
        print("The division of two numebers is: {:.2f}".format(a/b))
else:
    print("Wrong choice!!")