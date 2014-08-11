# Md. Khairullah Gaurab
# SUST, CSE, 20th Batch
#  gaurab.cse.sust@gmail.com

from __future__ import print_function
test = int(raw_input());

for i in xrange(test):
    N, S, K = map(int,raw_input().split());
    lis = map(int,raw_input().split());
    ans = [i+1 for i in xrange(N)] ;
    ans.sort(reverse=True);
    for j in xrange(N):
        print(ans[j],end=' ');
    print('')
