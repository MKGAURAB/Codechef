//Md. Kahirullah Gaurab
//CSE, SUST
//20th Batch
//gaurab.cse.sust@gmail.com

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>

using namespace std;
typedef long long ll;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int test, n;
	set<ll> ms;
	cin>>test;
	while(test--)
	{
		cin>>n;
		ms.clear();
		while(n--)
		{
			int aux;
			cin>>aux;
			ms.insert(aux);
		}
		ll res = (ll)ms.size()-1;
		res = (res*(res+1))>>1; 
		cout<<res<<endl;
	}
	return 0;
}