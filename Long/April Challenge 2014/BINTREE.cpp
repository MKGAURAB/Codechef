//Md. Khairullah Gaurab
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

int main (int argc, char const* argv[])
{
	int test, u, v, cnt, ans;
	map<int, int> mp;
	cin>>test;
	for (unsigned int i = 0; i < test; i += 1)
	{
		cin>>u>>v;
		mp.clear();
		cnt = 0;
                mp[u] = 0;
                while (u/2)
                {
                	mp[u/2] = mp[u]+1;
                	u/=2;
                }
                if(mp.find(v)==mp.end())
                {
                        bool flag = false;
                        while (v/2)
                        {
                        	cnt++;
                        	v/=2;
                        	if (mp.find(v)!=mp.end())
                        	{
                        		ans = mp[v] + cnt;
                        		flag = true;
                        		break;
                        	}
                        }
                        if (!flag)
                        {
                        	ans = mp[1] + cnt;
                        }                
                }
                else ans = mp[v]+cnt;
                cout<<ans<<endl;    
	}
	return 0;
}






