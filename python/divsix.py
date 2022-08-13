x=int(input("Enter the lower range: "))
y=int(input("Enter the upper range: "))
i=x
print("Numbers divisible by 6 in the range are: ")
while(i<=y):
    if(i%6==0):
        print(i)
    i+=1
