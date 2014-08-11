//Md. Khairullah Gaurab
//CSE, SUST
//20th Batch
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define SZ 100050
using namespace std;
typedef long long int ll;
ll res[SZ];
ll rres[SZ];
ll data[SZ];
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int test, N, K, i, j, k, l;
	cin>>test;
	while(test--)
	{
		cin>>N>>K;
		memset(res,0,sizeof(res));
		memset(rres,0,sizeof(rres));
		for(i=0; i<N; i++)
		{
			cin>>data[i];
		}
		res[0] = data[0];
		ll curMax = data[0];
		for(i=1; i<N; i++)
		{
			curMax = data[i]>(curMax+data[i])?data[i]:(curMax+data[i]);
			res[i] = res[i-1]>curMax?res[i-1]:curMax;
		}
		rres[N-1] = data[N-1];
		ll rcurMax = data[N-1];
		for(i=N-2; i>=0; i--)
		{
			rcurMax = data[i]>(rcurMax+data[i])?data[i]:(rcurMax+data[i]);
			rres[i] = rres[i+1]>rcurMax?rres[i+1]:rcurMax;
		}
		// cout<<"FROWARD: ";
		// for(i=0; i<N; i++)
		// {
		// 	cout<<res[i]<<" ";
		// }
		// cout<<"\nREVERSE: ";
		// for(i=0; i<N; i++)
		// {
		// 	cout<<rres[i]<<" ";
		// }
		// cout<<"\n";
		ll resMax = -1*(1LL<<62);
		//cout<<resMax<<endl;
		for(i=0; i<N; i++)
		{
			if(i+K+1>=N) break;
			resMax = resMax < res[i]+rres[i+K+1]? res[i]+rres[i+K+1] : resMax;
		}
		cout<<resMax<<endl;

	}
	return 0;
}