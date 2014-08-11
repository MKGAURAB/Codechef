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
const int SZ = 800005;

typedef long long Long;
typedef double dd;

int stree[(SZ*8)][12], LAZY[(SZ*8)], data[SZ], nhas[20000][12];

void convert2nhas(int num)
{
    int k, TMP[13];
    dd denum;
    nhas[num][0] = num;
    REP(i,1,11)
    {
        denum = log10(num);
        denum = (int)denum;
        denum = pow(10,denum);
        nhas[num][i] = (nhas[num][i-1]/(int)denum);
        nhas[num][i] += (nhas[num][i-1]%(int)denum)*10;
    }
}

void BuildTree(int root, int st, int en)
{
    if(st==en)
    {
        REP(i,0,11)
        {
            stree[root][i] = nhas[data[st]][i];
        }
        return ;
    }
    int mid = (st+en)>>1;
    int left = (root<<1);
    int right = (left + 1);

    BuildTree(left,st,mid);
    BuildTree(right,mid+1,en);
    REP(i,0,11)
    {
        stree[root][i] = max(stree[left][i],stree[right][i]);
    }
}

void UPDATE(int root, int st, int en, int i, int j, int val)
{
    int TMP[20], K;

    int mid = (st+en)>>1;
    int left = (root<<1);
    int right = (left + 1);

    if(LAZY[root])
    {
        LAZY[left] = (LAZY[left] + LAZY[root])%12;
        LAZY[right] = (LAZY[right] + LAZY[root])%12;

        REP(m,0,11)TMP[(m - LAZY[root] + 12) % 12] = stree[root][m];
        REP(m,0,11)stree[root][m] = TMP[m];

        LAZY[root] = 0;
    }
    if(st>j || en<i) return ;
    if(st>=i and en<=j)
    {
        LAZY[left] = (LAZY[left] + val)%12;
        LAZY[right] = (LAZY[right] + val)%12;

        REP(m,0,11)TMP[(m - val + 12) % 12] = stree[root][m];
        REP(m,0,11)stree[root][m] = TMP[m];

        return ;
    }
    UPDATE(left,st,mid,i,j,val);
    UPDATE(right,mid+1,en,i,j,val);

    REP(m,0,11)
    {
        stree[root][m] = max(stree[left][m],stree[right][m]);
    }
}

int QUERY(int root, int st, int en, int i, int j)
{
    int TMP[20], K;

    int mid = (st+en)>>1;
    int left = (root<<1);
    int right = (left + 1);

    if(LAZY[root])
    {
        LAZY[left] = (LAZY[left] + LAZY[root])%12;
        LAZY[right] = (LAZY[right] + LAZY[root])%12;

        REP(m,0,11)TMP[(m - LAZY[root] + 12) % 12] = stree[root][m];
        REP(m,0,11)stree[root][m] = TMP[m];

        LAZY[root] = 0;
    }

    if(st>j or en<i) return 0;
    if(st>=i and en<=j) return stree[root][0];

    return max(QUERY(left,st,mid,i,j), QUERY(right,mid+1,en,i,j));
}
int main(int argc, const char **argv)
{
    int N, Q, l, r, val, c;
    sf("%d",&N);
    REP(i,1,N)
    {
        sf("%d",&data[i]);
    }
    REP(i,1,10005) convert2nhas(i);
    BuildTree(1,1,N);
    sf("%d",&Q);
    REP(i,1,Q)
    {
        sf("%d",&c);
        if(c)
        {
            sf("%d %d",&l, &r);
            pf("%d\n",QUERY(1,1,N,l+1,r+1));
        }
        else
        {
            sf("%d %d %d",&l, &r, &val);
            UPDATE(1,1,N,l+1,r+1,(val%12));
        }
    }
    return 0;
}
