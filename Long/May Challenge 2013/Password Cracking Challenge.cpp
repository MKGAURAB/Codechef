#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
int main()
{
    int N, M, H, bline, h, d, l;
    string a;
    int PRIMES[]= {2,3,7,11,13,23};
    int LENGTH[]= {8,9,10,11,12};
    bline=0;
    long long int n = 15483653;
    cin>>N>>M>>H;
    for(int j=0; j<N; j++)
    {
        for(int k=0; k<M; k++)
        {
            a.clear();
            l = LENGTH[rand()%5];
            for(int i=0; i<l; i++)
            {
                h = rand()%6;
                d = (rand()%PRIMES[h]);
                if(d*2<=26) a+=(d*2)%26+'a';
                else a+=(n%26)+'a';
            }
            cout<<a<<endl;
            fflush(stdout);
        }
        cin>>n;
    }
    return 0;
}
