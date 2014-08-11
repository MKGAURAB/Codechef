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

const int inf = 1e9;
const int SZ = 1000+2;

typedef long Long;
typedef double dd;

Long x, y;

int main(int argc, const char **argv)
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int test;
    sf("%d",&test);
    REP(i,1,test)
    {
        sf("%ld %ld",&x, &y);
        if(x==0 and y==0) pf("YES\n");
        else if((x<0 and labs(x)%2==0) or (x>0 and x%2==1))
        {
            if(x<0)
            {
                if((y>=x and y<=(-1*x)) or labs(y)%2==0) pf("YES\n");
                else pf("NO\n");
            }
            else if(x>0)
            {
                if(y>=(-1*(x-1)) and y<=(x+1)) pf("YES\n");
                else if(labs(y)%2==0)
                {
                    if(y>0)
                    {
                        if(x<=y-1 and x>=(-1*(y))) pf("YES\n");
                        else pf("NO\n");
                    }
                    else if(y<0)
                    {
                        if(x<=(-1*y)+1 and x>=(y)) pf("YES\n");
                        else pf("NO\n");
                    }
                }
                else pf("NO\n");
            }
        }
        else if(labs(y)%2==0)
        {
            if(y>0)
            {
                if(x<=y-1 and x>=(-1*(y))) pf("YES\n");
                else pf("NO\n");
            }
            else if(y<0)
            {
                if(x<=(-1*y)+1 and x>=(y)) pf("YES\n");
                else pf("NO\n");
            }
            else pf("NO\n");
        }
        else pf("NO\n");
    }
    return 0;
}
