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
const int SZ = 100000;

typedef long long Long;
typedef double dd;

struct ADJ
{
    int x, y;
    ADJ(int _, int __)
    {
        x = _;
        y = __;
    }
};

struct INVER
{
    int x, y;
    bool operator<(const INVER& Z)const
    {
        return y>Z.y;
    }
    INVER(int _, int __)
    {
        x = _;
        y = __;
    }
};

vector<ADJ> LIST[SZ+7];
int Distance[SZ+7];
void Dijkastra(int src)
{
    Distance[src] = 0;
    priority_queue<INVER> Q;
    Q.push(INVER(src,0));
    while(!Q.empty())
    {
        int u =  Q.top().x;
        int w = Q.top().y;
        Q.pop();
        int k = LIST[u].size();
        k--;
        REP(i,0,k)
        {
            int v = LIST[u][i].x;
            int weight = LIST[u][i].y;
            if(Distance[v]>w+weight)
            {
                Distance[v] = w+ weight;
                Q.push(INVER(v,Distance[v]));
            }
        }
    }
}

int main(int argc, const char **argv)
{
    int N, M;
    sf("%d %d",&N, &M);
    REP(i,1,N)
    {
        Distance[i] = inf;
    }
    REP(i,1,N)
    {
        LIST[i].clear();
    }
    REP(i,1,M)
    {
        int x, y;
        sf("%d %d",&x, &y);
        if(x==y) continue;
        LIST[x].pb(ADJ(y,0));
        LIST[y].pb(ADJ(x,1));
    }
    Dijkastra(1);
    if(Distance[N]==inf) pf("-1\n");
    else pf("%d\n",Distance[N]);
    return 0;
}
