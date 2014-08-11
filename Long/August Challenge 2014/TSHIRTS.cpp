//Md. Khairullah Gaurab
//CSE, SUST  20th
//gaurab.cse.sust@gmail.com

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
const int SZ = 105;
const int mod = 1000000007;

typedef long long Long;
typedef double dd;

Long dp[107][(1<<11)];
int G[110][11];
int N, nxt;

Long rec(int col, int mask)
{
    if(mask==((1<<N)-1)) return 1;
    if(col>nxt) return 0;
    Long &ret = dp[col][mask];
    if(ret!=-1) return ret;
    ret = 0;
    ret+=rec(col+1,mask);
    ret%=mod;
    REP(i,0,9)
    {
        if(G[col][i] and !(mask&(1<<i)))
        {
            ret += rec(col+1,(mask|(1<<i)));
            ret %= mod;
        }
    }
    return ret;
}
int main(int argc, const char **argv)
{
    int test, in;
    string str;
    map<int,int> tsh;
    sf("%d",&test);
    REP(i,1,test)
    {
        sf("%d",&N);
        getchar();
        mem(G,0);
        tsh.clear();
        nxt=0;
        REP(j,1,N)
        {
            getline(cin,str);
            istringstream iss(str);
            while(iss>>in)
            {
                if(tsh.find(in)==tsh.end()) tsh[in] = nxt++;
                G[tsh[in]][j-1]=1;
            }
        }
        mem(dp,-1);
        Long res = rec(0,0)%mod;
        pf("%ld\n",res);
    }
    return 0;
}
