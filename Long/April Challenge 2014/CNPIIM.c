#include <stdio.h>
#include <math.h>
#include <string.h>

#define SZ 1662550

int dp[SZ];

int solve(int n) {
    int i;
    int SQ = sqrt(n);
    int ans = 0;
    for(i=1; i<=SQ; i++) ans += (n/i);
    ans = (2*ans) - (SQ*SQ);
    return dp[n] = ans;
}

int main(int argc, const char *argv[]) {
    int test, N, m, i, j;
    long long int res, tmp;
    scanf("%d",&test);
    memset(dp,-1,sizeof(dp));
    for(i=1; i<=test; i++) {
        scanf("%d",&N);
        res = 0LL;
        for(j=1; j<=N-1; j++) {
            if(dp[(N-j)*j-1]!=-1) tmp = dp[(N-j)*j-1];
            else tmp = solve(((N-j)*j)-1);
            res += tmp;
        }
        printf("%lld\n",res);
    }
    return 0;
}
