n=int(input("Enter the number of terms: "))
sum=0.0
for i in range(1,n+1):
    sum = sum + (1/(i**i))
print("Sum of series is: {:.5f}".format(sum))