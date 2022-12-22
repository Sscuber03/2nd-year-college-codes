import math
import time

def isPrime(n):
    if(n>1):
        for i in range(2,int(math.sqrt(n)+1)):
            if(n%i==0):
                return False
        return True
    return False

def main():
    t0 = time.time()
    count = 0
    low = int(math.pow(10, 6-1))
    high = int(math.pow(10,6)-1)
    for number in range(low, high+1):
        if isPrime(number):
            print(number, end = " ")
            count += 1
    print()
    print("Count of primes: ", count)
    t1 = time.time()
    print("Time Required: ", t1-t0)
    
if __name__ == "__main__":
    main()