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
const int SZ = 17;

typedef long long Long;
typedef double dd;


Long modPow(Long a, Long x, Long p) {
    //calculates a^x mod p in logarithmic time.
    Long res = 1;
    while(x > 0) {
        if( x % 2 != 0) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        x /= 2;
    }
    return res;
}

Long modInverse(Long a, Long p) {
    //calculates the modular multiplicative of a mod m.
    //(assuming p is prime).
    return modPow(a, p-2, p);
}
Long modBinomial(Long n, Long k, Long p) {
// calculates C(n,k) mod p (assuming p is prime).

    Long numerator = 1; // n * (n-1) * ... * (n-k+1)
    for (int i=0; i<k; i++) {
        numerator = (numerator * (n-i) ) % p;
    }

    Long denominator = 1; // k!
    for (int i=1; i<=k; i++) {
        denominator = (denominator * i) % p;
    }

    // numerator / denominator mod p.
    return ( numerator* modInverse(denominator,p) ) % p;
}


int main(int argc, const char **argv)
{
    //freopen("input.txt","r",stdin);
    int test;
    Long n, k, p;
    p = 1000000007;
        sf("%lld",&n);
        Long tmp = (n/2)+(n%2);
        k = tmp - 7;
        Long pos = tmp - 1;
        if(tmp>=7) pf("%lld\n",modBinomial(pos,k,p));
        else pf("0\n");
    return 0;
}
