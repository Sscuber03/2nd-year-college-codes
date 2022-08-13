x=int(input("Enter a number : "))
sum=0
copy=x
while(copy>0):
    d=copy%10
    sum = sum + (d**3)
    copy = copy // 10
if(x==sum):
    print("Armstrong number")
else:
    print("Not an Armstrong number")
