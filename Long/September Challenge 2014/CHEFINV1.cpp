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
const int SZ = 200000 + 7;

//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};

typedef long long Long;
typedef double dd;

#define LOGSZ 18

Long tree[SZ];
Long  arr[SZ];
vector<Long> org;
Long N;

struct data1
{
    int val, indx;
};
data1 b[SZ];
bool comp(data1 p, data1 q)
{
    if (p.val == q.val) return p.indx < q.indx;
    return p.val < q.val;
}

struct data2
{
    int cmd, indx, x, y, mark;
    data2() {}
    data2(int p, int q, int r, int s, int t)
    {
        cmd = p, indx = q, x = r, y = s, mark = t;
    }
};

Long RES[SZ];
vector <data2> G[SZ];
// add v to value at x
void aset(Long x, Long v)
{
    while (x <= N)
    {
        tree[x] += v;
        x += (x & -x);
    }
}

// get cumulative sum up to and including x
Long get(Long x)
{
    Long res = 0;
    while (x)
    {
        res += tree[x];
        x -= (x & -x);
    }
    return res;
}

// get largest value with cumulative sum less than or equal to x;
// for smaLongest, pass x-1 and add 1 to result
Long getind(Long x)
{
    Long idx = 0, mask = N;
    while (mask && idx < N)
    {
        Long t = idx + mask;
        if (x >= tree[t])
        {
            idx = t;
            x -= tree[t];
        }
        mask >>= 1;
    }
    return idx;
}


int main(int argc, const char **argv)
{
    //freopen("input.txt","r",stdin);
    int NN, Q, k, val, uu, vv;
    Long ans, tmp;
    sf("%d %d", &NN, &Q);
    org.clear();
    REP(i, 1, NN) G[i].clear();
    REP(i, 1, NN)
    {
        sf("%lld", &arr[i]);
        org.pb(arr[i]);
    }
    unq(org);
    REP(i, 1, NN)
    {
        arr[i] = (lower_bound(org.begin(), org.end(), arr[i]) - org.begin()) + 1;
        b[i].val = (int) arr[i];
        b[i].indx = i;
    }
    stable_sort(b + 1, b + NN + 1, comp);
    ans = 0LL;
    N = NN;
    REP(i, 1, NN)
    {
        ans += (Long)get(NN) - get(b[i].indx);
        aset(b[i].indx, 1);
    }
    REP(i, 1, Q) RES[i] = ans;
    REP(i, 1, Q)
    {
        sf("%d %d", &uu, &vv);
        if (uu > vv) swap(uu, vv);
        G[arr[vv]].pb(data2(1, i, uu, vv - 1, 1)); ///cmd, indx, x, y, mark
        G[arr[uu]].pb(data2(1, i, uu, vv - 1, -1)); ///cmd, indx, x, y, mark
        if (arr[uu] > arr[vv]) RES[i]--;
        if (arr[uu] < arr[vv]) RES[i]++;
    }
    REP(i, 1, (NN - 1))
    {
        G[arr[i]].pb(data2(0, i, 0, 0, 0));
    }
    mem(tree, 0);
    REP(i, 1, NN)
    {
        k = G[i].size();
        REP(j, 0, (k - 1))
        {
            if (G[i][j].cmd == 0)
            {
                aset(G[i][j].indx, 1);
            }
            else
            {
                tmp = get(G[i][j].y) - get(G[i][j].x);
                if (G[i][j].mark == 1) RES[ G[i][j].indx ] += tmp;
                else RES[ G[i][j].indx ] -= tmp;
            }
        }
    }
    mem(tree, 0);
    REPR(i, 1, NN)
    {
        k = G[i].size();
        REP(j, 0, (k - 1))
        {
            if (G[i][j].cmd == 0)
            {
                aset(G[i][j].indx, 1);
            }
            else
            {
                tmp = get(G[i][j].y) - get(G[i][j].x);
                if (G[i][j].mark == -1) RES[ G[i][j].indx ] += tmp;
                else RES[ G[i][j].indx ] -= tmp;
            }
        }
    }

    REP(i, 1, Q) pf("%lld\n", RES[i]);

    return 0;
}