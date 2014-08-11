#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string a, b, c, d;
        int t;
        a.clear();
        b.clear();
        cin>>a>>b;
        a+=b;
        sort(a.begin(),a.end());
        cin>>t;
        for(int i=0; i<t; i++) {cin>>c; d+=c;}
        sort(d.begin(),d.end());
        int pos=-1;
        bool yes=true;
        for(int i=0; yes&&i<d.size(); i++)
        {
            yes = (pos=a.find(d[i],pos+1))!=string::npos;
        }
        if(yes) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
