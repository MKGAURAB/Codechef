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
#define all(a) a.begin(),a.end(),
#define REP(i,a,b) for(int i=a; i<=b; ++i)
#define REPR(i,a,b) for(int i=b; i>=a; --i)
#define mp(a,b) make_pair(a,b)
#define fs first
#define sc second
#define unq(vec) stable_sort(vec.begin(),vec.end());\
                 vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())));

using namespace std;

const int inf = 2000000000;
const int SZ = 400+2;

typedef long long Long;
typedef double dd;

vector<int> ord;
vector<int> seq[SZ+7];
vector<int > sseq;

bool comp(int a, int b)
{
    int u, v, k;
    k = seq[a].size();
    if(k) u = seq[a][k-1];
    else u = inf;

    k = seq[b].size();
    if(k) v = seq[b][k-1];
    else v = inf;

    return u<v;
}

int main(int argc, const char **argv)
{
    int test, N, M, time, C;
    sf("%d",&test);
    REP(i,1,test)
    {
        sf("%d %d",&N, &M);
        REP(j,1,N)
        {
            seq[j].clear();
        }
        sseq.clear();
        ord.clear();
        REP(j,1,M)
        {
            sf("%d",&C);
            seq[C].pb(j);
            ord.pb(C);
        }
        REP(j,1,405)
        {
            sort(seq[j].begin(),seq[j].end(),greater<int>());
        }
        time = 0;
        REP(j,0,M-1)
        {
            int v = ord[j];

            if(sseq.size()<N)
            {

                bool flag = false;
                for(int as : sseq)
                {
                    if(as==v) flag = true;
                }
                if(flag)
                {
                    time += 0;
                    seq[v].pop_back();
                }
                else
                {
                    time += 1;
                    sseq.pb(v);
                    seq[v].pop_back();
                }
            }
            else
            {
                stable_sort(all(sseq) comp);
                bool flag = false;
                for(int as : sseq)
                {
                    if(as==v) flag = true;
                }
                if(flag)
                {
                    time += 0;
                    seq[v].pop_back();
                }
                else
                {
                    sort(all(sseq) comp);
                    sseq.pop_back();
                    time++;
                    sseq.pb(v);
                    seq[v].pop_back();
                }
            }
        }
        pf("%d\n",time);
    }
    return 0;
}
