#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#define maxx 100000
using namespace std;
void sieve();
void check();
vector<int> Sieve;
int numbers[maxx];
int csum[maxx][5];
int main()
{
    int Test, A, B, K;
    sieve();
    check();
    cin>>Test;
    while(Test--)
        {
            cin>>A>>B>>K;
           if(A==2 )  cout<<csum[B][K]<<endl;
           else cout<<csum[B][K]-csum[A-1][K]<<endl;
        }
    return 0;
}

void sieve()
{
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
void check()
{
    map<int, int> mp;
    for(int i=2; i<=maxx; i++)
        {
            mp.clear();
            if(numbers[i])
                {
                    int temp = i;
                    int j = 0;
                    int nxt = 0;
                    while(temp>1)
                        {
                            if(temp%Sieve[j]==0)
                                {
                                    temp/=Sieve[j];
                                    if(mp.find(Sieve[j])==mp.end()) mp[Sieve[j]]=nxt++;
                                }
                            else j++;
                        }
                    numbers[i]=nxt;
                }
        }
    for(int i=1; i<=5; i++)
        {
            for(int j=2; j<=maxx; j++)
                {
                    if(i==1&&(numbers[j]==0||numbers[j]==i))csum[j][i] = 1;
                    else if(i>1&&numbers[j]==i) csum[j][i] =1;
                }
            for(int j=3; j<=maxx; j++)
                {
                    csum[j][i] += csum[j-1][i];
                }
        }
}
