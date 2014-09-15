#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <algorithm>

#define sf scanf
#define pf printf
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define all(a) (a.begin(),a.end())
#define REP(i,a,b) for(int i=a; i<=b; ++i)
#define REPR(i,a,b) for(int i=b; i>=a; --i)
#define mp(a,b) make_pair(a,b)
#define fs first
#define sc second
#define unq(vec) stable_sort(vec.begin(),vec.end());\
                 vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())));

using namespace std;

const int inf = 2000000000;
const int SZ = 26 + 7;

typedef long long Long;
typedef double dd;

Long M;
Long root,test;
Long  lpart, lans, sum, MOD;
Long GPW(Long NN)
{
    Long ANS = 1LL;
    Long RET = 0;
    Long NMOD = (MOD*30);
    REP(i,1,5)
    {
        ANS = ((ANS*NN)%NMOD);
        if(i==3)
        {
            RET = (RET + (ANS*10)%NMOD)%NMOD;
        }
        else if(i==4)
        {
            RET = (RET + (ANS*15)%NMOD)%NMOD;
        }
        else if(i==5)
        {
            RET = (RET + (ANS*6)%NMOD)%NMOD;
        }
    }
    RET = RET - (NN%NMOD) + NMOD;
    RET = RET%NMOD;
    RET = RET/30;
    return RET;
}
int main(int argc, const char **argv)
{
    sf("%d",&test);
    REP(i,1,test)
    {
        sf("%lld %lld",&M, &MOD);
        root = (Long) sqrtl(M);
        sum = 0;
        REP(j,1,root)
        {
            lans = 1;
            REP(k,1,4)
            {
                lans = (lans*j)%MOD;
            }
            lpart = floorl((M/j));
            lans = (lpart*lans)%MOD;
            sum = (sum+lans)%MOD;
            if(((Long)j*(Long)(j+1))<=M)
            {
                Long hi = floorl(((M/(j))));
                Long lw = floorl((M/(j+1)));
                lans = (GPW(hi) - GPW(lw)+MOD)%MOD;
                lans = (lans*(j))%MOD;
                sum = (sum + lans)%MOD;
            }
        }
        pf("%lld\n",sum);
    }
    return 0;
}
