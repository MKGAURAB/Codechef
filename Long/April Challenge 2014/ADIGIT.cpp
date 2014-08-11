//Md. Khairullah Gaurab
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>


using namespace std;

const int MAX = 100005;


int arr[MAX][10];
int data[MAX];

int main (int argc, char const* argv[])
{
	int n, m, in, tmpg, tmpl, cnt;
	string str;
	while (cin>>n>>m)
	{
		memset(arr,0,sizeof(arr));
		cin>>str;
		for (unsigned int i = 1; i <= n; i += 1)
		{
			in = str[i-1]-'0';
		        data[i] = in;
			arr[i][in]++;
			for (unsigned int j = 0; j < 10; j += 1)
			{
				arr[i][j] += arr[i-1][j];
			}
		}
		for (unsigned int i = 0; i < m; i += 1)
		{
			cin>>in;
			tmpl = tmpg = 0;
			for (int j = data[in]; j < 10; j += 1)
			{
			        cnt = arr[in-1][j];
				tmpl += (cnt*data[in])-(j*cnt);
			}
			for (int j = 0; j <data[in]; j += 1)
			{
				cnt = arr[in-1][j];
				tmpg += (cnt*data[in])-(j*cnt);
			}
			cout<<(tmpg-tmpl)<<endl;
		}
	}
	return 0;
}


