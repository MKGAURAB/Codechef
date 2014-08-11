//Md. Khairullah Gaurab
//SUST, CSE, 20th Batch
//Session: 2011-12

#include <bits/stdc++.h>
using namespace std;
template <class T> T GCD(T a, T b){  if(b==0) return a; return GCD(b,a%b);}
typedef long long int ll;
int main()
{
    ll Test, qrt, tmp, m;
    ll N;
    scanf("%lld",&Test);
    while(Test--)
    {
        ll sum = 0;
        scanf("%lld",&N);
        qrt = (int)sqrt(N);
        for(int i=1; i<=qrt; i++)
            sum+=(N/i);
        tmp = (sum*2) - (qrt*qrt);
        N = (N*N);
        m = GCD(N,tmp);
        N /=m;
        tmp /=m;
        printf("%lld/%lld\n",tmp,N);
    }
    return 0;
}
