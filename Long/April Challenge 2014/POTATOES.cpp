//Md. Khairullah Gaurab
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstring>
#define maxx 3000

using namespace std;

vector<int> Sieve;
int numbers[maxx+10];

void sieve()
{
    memset(numbers,0,sizeof(numbers));
    int Sqrt = sqrt(maxx);
    numbers[0]=numbers[1]=1;
    for(int i=2; i<=Sqrt; i++)
    {
        if(numbers[i]==0)
            for(int j=i*i; j<=maxx; j+=i)
            {
                numbers[j] = 1;
            }
    }
    for(int i=0; i<=maxx; i++)
    {
        if(!numbers[i]) Sieve.push_back(i);
    }
}

int main(int argc, const char *argv[])
{
    int test, x, y, sum, mn;
    cin>>test;
    sieve();
    for(int i=0; i<test; i++)
    {
        cin>>x>>y;
        sum = x+y;
        mn = upper_bound(Sieve.begin(),Sieve.end(),sum)-Sieve.begin();
        cout<<(Sieve[mn]-sum)<<endl;
    }
    return 0;
}
