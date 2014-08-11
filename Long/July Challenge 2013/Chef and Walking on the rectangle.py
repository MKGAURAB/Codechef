#-------------------------------------------------------------------------------
# Name:        Chef and Walking on the rectangle
# Purpose:
#
# Author:      Md. Khairullah
#
# Created:     13/07/2013
# Copyright:   (c) Md. Khairullah 2013
# Licence:     <your licence>
#-------------------------------------------------------------------------------

def main():
    Test = int(raw_input())
    for i in xrange(Test):
        n, m, k = map(int,raw_input().split())
        if n==1 and m==1:
            print 0
        elif n>=2 and m>=2:
            if k%2==0:
                print k//2
            else :
                print (k//2)+1
        elif (n==1 and m==2) or (n==2 and m==1):
            print 0
        else :
            print k

if __name__ == '__main__':
    main()
