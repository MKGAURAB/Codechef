/*
 * COLARR.cpp
 *
 *  Created on: Feb 9, 2014
 *      Author: gaurab
 */
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

#define MAX 1010

using namespace std;

int arr[MAX];
int win[MAX][MAX];
int loose[MAX][MAX];
int info[MAX][2];
int DP[MAX][MAX];
int N, M, K;


int rec(int pos, int rep)
{
	int &ret = DP[pos][rep];
	if(pos>N) return 0;
	if(ret!=-1) return ret;
	ret = info[pos][0] + rec(pos+1,rep);
	if(rep) ret = max(ret,info[pos][1]+rec(pos+1,rep-1));
	return ret;
}

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);
	int test;
	cin >> test;
	while (test--)
	{
		cin >> N >> M >> K;
		memset(DP, -1, sizeof(DP));
		for (int i = 1; i <= N; ++i)
		{
			cin >> arr[i];
		}
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= M; ++j)
			{
				cin >> win[i][j];
			}
		}
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= M; ++j)
			{
				cin >> loose[i][j];
			}
		}
		int mn = -1;
		for (int i = 1; i <= N; ++i)
		{
			info[i][0] = win[i][arr[i]];
			mn = -1;
			for (int j = 1; j <= M; ++j)
			{
				mn = max(mn,
						((win[i][j] - loose[i][j])));
			}
			info[i][1] = mn;
		}
		cout<<rec(1,K)<<endl;
	}

	return 0;
}
