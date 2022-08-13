x=int(input("Enter a number: "))
sump=0
sumn=0
cp=0
cn=0
while(x!=-1):
    if(x>0):
        sump+=x
        cp+=1
    elif(x<-1):
        sumn+=x
        cn+=1
    x=int(input("Enter a number: "))
print("Sum of positive number is: ",sump)
print("Average of positive is: ",sump/cp)
print("Sum of negetive number is: ",sumn)
print("Average of negetive is: ",sumn/cn)
