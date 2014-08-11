import math
var = 1010
DP = [[0]*var for i in xrange(var)]
for i in xrange(var):
    for j in xrange(0,i+1):
        if i==j or j==0:
            DP[i][j] = 1
        elif j==1:
            DP[i][j]=i
        else:
            DP[i][j] = DP[i-1][j] + DP[i-1][j-1]
r = raw_input()
r = int(r)
for x in xrange(r):
    w = raw_input()
    s, n, m, k  = w.split();
    s = int(s)
    n = int(n)
    m = int(m)
    k = int(k)
    if k+1>n:
        print "0.000000"
    elif s==n:
        print "1.000000"
    else :
        a = 0.0
        for i in xrange(k,m):
            if s-m>=n-i-1 and m-1>=i and n-i-1>=0:
                c = DP[m-1][i]*DP[s-m][n-i-1]
                a = a + c
        b = DP[s-1][n-1]
        answer = (a*1.0)/(b*1.0);
        print "%.6f"%answer
