import math
import sys
import os

ARR = [2, 3, 5, 7, 11, 13, 19, 23, 29]

def BigMod(A,N,M):
    if N==1:
        return A%M
    X = BigMod(A,N/2,M)
    X = X%M
    X =(X*X)%M
    if N%2==1:
        X = (X*A)%M
    return X
def Primality(N):
    for i in range(9):
        a = ARR[i]
        if a>=N:
            continue
        D = N-1
        S = 0
        while D%2==0:
            S = S+1
            D = D/2
        if BigMod(a,D,N)==1:
            continue
        flag=0
        for j in range(0,S):
            if BigMod(a,(2**j)*D,N)==N-1:
                flag = 1
                break
        if flag==0:
            return 0
    return 1
        
        
        
def FindPrime(N):
    if N==2:
        return 2
    if N%2==0:
        N = N-1
    while N>0:
        if Primality(N)==1:
             return N
        N-=2
def main():
    Test = int(raw_input())
    while Test>0:
        N = int(raw_input())
        print FindPrime(N);
        Test-=1
if __name__=="__main__":main()
