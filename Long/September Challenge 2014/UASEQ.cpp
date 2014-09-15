#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
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
#define all(a) a.begin(),a.end()
#define REP(i,a,b) for(int i=a; i<=b; ++i)
#define REPR(i,a,b) for(int i=b; i>=a; --i)
#define mp(a,b) make_pair(a,b)
#define fs first
#define sc second
#define unq(vec) stable_sort(vec.begin(),vec.end());\
    vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())));

using namespace std;

const int inf = 2000000000;
const int SZ = 100000 + 7;

//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};

typedef long long Long;
typedef double dd;
Long data[SZ];
vector<pair<Long, Long> > pro;
bool comp(pair<Long, Long> a, pair<Long, Long> b)
{
	if(a.fs==b.fs) return a.sc<b.sc;
	return a.fs<b.fs;
}
int main(int argc, const char **argv)
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int N, K, len, cnt;
    Long anot, d, X;
    sf("%d %d", &N, &K);
    pro.clear();
    REP(i, 0, (N - 1))
    {
        sf("%lld", &data[i]);
        if (i > 0)
        {
            d = (data[i] - data[i-1]);
            anot = data[i] - i * d;
            pro.pb(mp(anot, d));
        }
    }
    stable_sort(all(pro));
    len = pro.size();
    bool flag = false;
    int pos;
    REP(i, 0, (len - 1))
    {
        if (flag) break;
        cnt = 0;
        REP(j, 0, (N - 1))
        {
            X = (pro[i].fs) + j * (pro[i].sc);
            if (X != data[j]) cnt++;
        }
        if (cnt <= K)
        {
            pos = i;
            flag = true;
        }
    }
    REP(j, 0, (N - 1))
    {
        X = (pro[pos].fs) + j * (pro[pos].sc);
        pf("%lld ",X);
    }
    pf("\n");
    return 0;
}