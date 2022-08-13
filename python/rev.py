x=int(input("Enter a number: "))
y=0
while(x>0):
    d=x%10
    y=(y*10)
    y+=d
    x=x//10
print("Reverse is: ",y)
