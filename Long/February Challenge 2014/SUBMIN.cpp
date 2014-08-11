/*
 * SUBMIN.cpp
 *
 *  Created on: Feb 7, 2014
 *      Author: gaurab
 */
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char **argv) {
	ios::sync_with_stdio(false);
	int N, Q, res, mn, in;
	cin>>N;
	vector<int> arr(N);
	for(int i=0; i<N; i++) cin>>arr[i];
	cin>>Q;
	for(int i=0; i<Q; ++i)
	{
		cin>>in;
		res = 0;
		for(int j=0; j<N; j++)
		{
			for(int k=j; k<N; k++)
			{
				mn = 1<<28;
				for(int l=j; l<=k; ++l)
				{
					mn = min(mn,arr[l]);
				}
				if(mn==in) res++;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}




