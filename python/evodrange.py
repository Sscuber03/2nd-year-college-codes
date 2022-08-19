m=int(input("Enter lower limit: "))
n=int(input("Enter upper limit: "))
for i in range(m,n+1):
    if(i%2==0):
        print(i, " is even")
    else:
        print(i, " is odd")
