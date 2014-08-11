/*
 * LCPESY.cpp
 *
 *  Created on: Feb 7, 2014
 *      Author: gaurab
 */
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;
int ARR[256];
int ARR1[256];

int main(int argc, char **argv) {
	ios::sync_with_stdio(false);
	int test, l1, l2, res;
	string in1, in2;
	cin>>test;
	while(test--)
	{
		memset(ARR,0,sizeof(ARR));
		memset(ARR1,0,sizeof(ARR1));
		res = 0;
		cin>>in1;
		cin>>in2;
		l1 = in1.length();
		l2 = in2.length();

		for(int i=0; i<l1; ++i)
		{
			ARR[(int)in1[i]]++;
		}
		for(int i=0; i<l2; i++)
		{
			ARR1[(int)in2[i]]++;
		}
		for(int i=0; i<256; i++)
		{
			if(ARR[i] and ARR1[i])
			{
				res+=min(ARR[i],ARR1[i]);
			}
		}
		cout<<res<<endl;
	}
	return 0;
}




