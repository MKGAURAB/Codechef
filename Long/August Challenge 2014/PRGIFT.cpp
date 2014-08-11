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

typedef long long Long;
typedef double dd;


int main(int argc, const char **argv)
{
    int test, n, k, sum, flag;
    vector<int> arr;
    sf("%d",&test);
    REP(i,1,test)
    {
        sf("%d %d",&n, &k);
        arr = vector<int>(n+1);
        REP(j,0,n-1)
        {
            sf("%d",&arr[j]);
        }
        sum = flag = 0;
        REP(SZ,k,n)
        {
            SZ = SZ?SZ:1;
            if(flag) break;
            for (int j=0; j+SZ-1<n; j++)
            {
                sum = 0;
                REP(m,j,j+SZ-1)
                {
                    if(arr[m]%2==0) sum++;
                }
                if(sum==k)
                {
                    cout<<"YES"<<endl;
                    flag = 1;
                    break;
                }
            }
        }
        if(!flag) cout<<"NO"<<endl;
    }
    return 0;
}
