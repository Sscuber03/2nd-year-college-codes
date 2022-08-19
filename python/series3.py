n=int(input("Enter the number of terms: "))
sum=0.0
fact=1
for i in range(1,n+1):
    sum = sum + (1/fact)
    fact = fact*(i+1)
print("Sum of series is:", sum)