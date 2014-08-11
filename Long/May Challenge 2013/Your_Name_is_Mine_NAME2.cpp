#include<iostream>
#include<string>
using namespace std;
int main()
{
    int T, l1, l2;
    string a, b;
    cin>>T;
    while(T--)
    {
        a.clear();
        b.clear();
        cin>>a>>b;
        l1 = a.length();
        l2 = b.length();
        bool OK=true;
        int pos=-1;
        if(l1<l2)
        {
            for(int i=0; OK&&i<l1; i++)
            {
                OK=(pos=b.find(a[i],pos+1))!=string::npos;
            }
        }
        else
        {
            for(int i=0; OK&&i<l2; i++)
            {
                OK=(pos=a.find(b[i],pos+1))!=string::npos;
            }
        }
        if(OK) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
