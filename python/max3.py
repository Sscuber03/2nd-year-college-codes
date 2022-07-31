a=int(input("Enter first numbers: "))
b=int(input("Enter second numbers: "))
c=int(input("Enter third numbers: "))
if(a>b and a>c):
    print("Max is: ", a)
elif(b>a and b>c):
    print("Max is: ", b)
else:
    print("Max is: ", c)