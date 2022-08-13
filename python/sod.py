x=int(input("Enter a number: "))
sum=0
while(x>0):
    d=x%10
    sum+=d
    x=x//10
print("The sum of digit is: ",sum)
