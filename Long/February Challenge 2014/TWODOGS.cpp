/*
 * TWODOGS.cpp
 *
 *  Created on: Feb 7, 2014
 *      Author: gaurab
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <utility>
#include <set>

#define MAX 1000500

using namespace std;

int fhash[MAX];
int bhash[MAX];
int arr[MAX];

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);
	int i, N, K, mn;
	cin >> N >> K;
	memset(fhash, 0, sizeof(fhash));
	memset(bhash, 0, sizeof(bhash));

	for (i = 1; i <= N; i++)
		cin >> arr[i];

	for (i = 1; i <= N; i++)
	{
		if (fhash[arr[i]] == 0)
			fhash[arr[i]] = i;
	}
	for (i = N; i >= 1; i--)
	{
		if (bhash[arr[i]] == 0)
			bhash[arr[i]] = (N - i) + 1;
	}
	mn = (1 << 28);
	for (i = 1; i <= N; i++)
	{
		if (((K - arr[i]) != arr[i]) and (K - arr[i]) >= 0
				and fhash[(K - arr[i])] != 0)
		{
			mn = min(mn, max(fhash[arr[i]], fhash[(K - arr[i])]));
		}
	}
	for (i = 1; i <= N; i++)
	{
		if (((K - arr[i]) != arr[i]) and (K - arr[i]) >= 0
				and bhash[(K - arr[i])] != 0)
		{
			mn = min(mn, max(fhash[arr[i]], bhash[(K - arr[i])]));
		}
	}
	for (i = 1; i <= N; i++)
	{
		if (((K - arr[i]) != arr[i]) and (K - arr[i]) >= 0
				and bhash[(K - arr[i])] != 0)
		{
			mn = min(mn, max(bhash[arr[i]], bhash[(K - arr[i])]));
		}
	}
	if (mn == (1 << 28))
		mn = -1;
	cout << mn << endl;
	
	return 0;
}

