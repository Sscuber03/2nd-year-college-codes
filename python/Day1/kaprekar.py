import math

def isKaprekar(n):
    if n==1:
        return True
    square = n*n
    copy = square
    digitc = 1
    while(copy!=0):
        digitc += 1
        copy = copy//10
    d=0
    while(d<digitc):
        d += 1
        p = (int)(math.pow(10,d))
        if(p==n):
            continue
        sum = square//p + square%p
        if sum==n:
            return True
    return False

def main():
    a = int(input("Enter a number to check if Kaprekar number or not: "))
    res = isKaprekar(a)
    if res:
        print("The given number is Kaprekar number")
    else:
        print("The give number is not Kaprekar number")

if __name__=="__main__":
    main()
