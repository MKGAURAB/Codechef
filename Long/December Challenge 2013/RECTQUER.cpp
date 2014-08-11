//Md. Khairullah Gaurab
//CSE, SUST
//20th Batch

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <algorithm>
#define SZ 90050

using namespace std;

struct info{
	int DATA[11];
	info()
	{
		for (int i = 0; i <=10; ++i)
		{
			DATA[i] = 0;
		}
	}
};
info ARRAY[SZ];
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int N,x1,y1,x2,y2,tmp,Q;
	cin>>N;
	for (int i = 1; i <= N*N; ++i)
	{
		cin>>tmp;
		ARRAY[i].DATA[tmp] = 1;
	}
	for (int i = 1; i <= N*N; ++i)
	{
		for(int j=1; j<=10; j++) ARRAY[i].DATA[j] += ARRAY[i-1].DATA[j];
	}
	cin>>Q;
	info res;
	int ans;
	for(int i=0; i<Q; i++)
	{
		cin>>x1>>y1>>x2>>y2;
		for (int k = 1; k <=10; ++k)
		{
			res.DATA[k]=ans=0;
		}
		for(int j=x1; j<=x2; j++)
		{
			for (int k = 1; k <=10; ++k)
			{
				res.DATA[k] += ARRAY[(int)((j*N)-(N-y2))].DATA[k] - ARRAY[(int)((j*N)-(N-y1)-1)].DATA[k];
			}
		}
		for (int k = 1; k <=10; ++k)
		{
			if(res.DATA[k]) ans++;
		}
		cout<<ans<<endl;
		
	}
	return 0;
}