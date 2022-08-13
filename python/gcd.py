x=int(input("Enter the first number: "))
y=int(input("Enter the second number: "))
while(y>0):
    if x%y==0:
        print("GCD is: ",y)
        break
    else:
        (x,y)=(y,x%y)
