n=int(input("Enter the number of terms: "))
sum=0.0
for i in range(1,n+1):
    sum = sum + (1/i)
print("Sum of series is: {:.2f}".format(sum))

