/*
 * LMATRIX.cpp
 *
 *  Created on: Feb 16, 2014
 *      Author: Md.Khairullah
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <numeric>

using namespace std;
const int MAX = 250;
int arr[MAX][MAX];

class info{
	public:
	int x1, y1, x2, y2;
	info(int a, int b, int c, int d)
	{
		x1 = a;
		y1 = b;
		x2 = c;
		y2 = d;
	}
};

vector<info> resv;

int main(int argc, char **argv) {
	ios::sync_with_stdio(false);
	int N, M, res, len;
	cin>>N>>M;
	for(int i=1; i<=N; ++i)
	{
		for(int j=1; j<=M; j++)
		{
			cin>>arr[i][j];
		}
	}
	res=0;
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=M; j++)
		{
			if(arr[i][j]%5==0)
			{
				res+=4;
				for(int k=0; k<4; k++)
				{
					resv.push_back(info(i,j,i,j));
				}
			}
			else
			{
				while((arr[i][j]+1)%5!=0)
				{
					res+=1;
					arr[i][j]+=1;
					resv.push_back(info(i,j,i,j));
				}
			}
		}
	}
	resv.push_back(info(1,1,N,M));
	cout<<(res+1)<<endl;
	len = resv.size();
	for(int i=0; i<len; i++)
	{
		cout<<resv[i].x1<<" "<<resv[i].y1<<" "<<resv[i].x2<<" "<<resv[i].y2<<endl;
	}
	return 0;
}





