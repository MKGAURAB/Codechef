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
const int SZ = 100000 + 7;
const int MOD = 1000000007;    
typedef long long Long;
typedef double dd;
Long root = 1LL, level= 1LL;
char arr[SZ];    
int main(int argc, const char **argv)
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int test, len;

    sf("%d",&test);
    REP(i,1,test)
    {
    	sf("%s",arr);
    	len = strlen(arr);
    	root = level = 1LL;
    	REP(j,0,(len-1))
    	{
    		if(arr[j]=='l')
    		{
    			if((level&(1LL)))
    			{
    				root<<=1LL;
    				root%=MOD;
    			}
    			else
    			{
    				root<<=1LL;
    				root -= 1;
    				root += MOD;
    				root %= MOD;
    			}
    		}
    		else
    		{
    			if((level&(1LL)))
    			{
    				root<<=1LL;
    				root += 2;
    				root %= MOD;
    			}
    			else
    			{
    				root<<=1LL;
    				root += 1;
    				root %= MOD;
    			}
    		}
    		level++;
    	}
    	pf("%lld\n",root);
    }
    return 0;
}