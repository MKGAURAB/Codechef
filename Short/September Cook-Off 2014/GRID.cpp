// Md. Khairullah Gaurab
// CSE, SUST 20th Batch
// gaurab.cse.sust@gmail.com

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

using namespace std;

const int inf = 2000000000;
const int MOD = 1007;

typedef long long Long;
typedef double DD;

#define sf scanf
#define pf printf
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define REP(i,a,b) for(int i=a; i<=b; ++i)
#define REPR(i,a,b) for(int i=b; i>=a; --i)
#define mp(a,b) make_pair(a,b)
#define fs first
#define sc second
#define SZ(s) ((int)s.size())
#define PI 3.141592653589793
#define VS          vector<string>
#define VI          vector<int>
#define VD          vector<DD>
#define VLL         vector<Long>
#define lim 1005
#define unq(vec) stable_sort(vec.begin(),vec.end());\
vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())));
#define BE(a)       a.begin(),a.end()
#define rev(a)      reverse(BE(a));
#define sorta(a)    stable_sort(BE(a))
#define sortc(a)    sort(BE(a),comp)

int G[lim][lim];
int T[lim][lim];

string str;
int main(int argc, const char **argv)
{
    ios::sync_with_stdio(false);
    int test, N, len;
    cin>>test;
    REP(i,1,test)
    {
        mem(G,0);
        mem(T,0);
        cin>>N;
        REP(j,1,N)
        {
            cin>>str;
            REP(k,1,N)
            {
                if(str[k-1]=='#') G[j][k] = T[j][k] = 1;
            }
            REPR(k,1,N)
            {
                G[j][k] += G[j][k+1];
            }
        }
        REP(j,1,N)
        {
            REPR(k,1,N) T[k][j]+=T[k+1][j];
        }
        //REP(j,1,N){REP(k,1,N){cout<<G[j][k];}cout<<endl;}
        //REP(j,1,N){REP(k,1,N){cout<<T[j][k];}cout<<endl;}
        int sum = 0;
        REP(j,1,N)
        {
            REP(k,1,N)
            {
                if(!G[j][k] and !T[j][k]) sum++;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
