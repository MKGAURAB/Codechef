#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main()
{
    int Test;
    cin>>Test;
    while(Test--)
    {
            string str;
            cin>>str;
            int l = str.length();
            int DATA[27];
            for(int i=0; i<27; i++) DATA[i]=1;
            int mid = (l>>1);
            int rg;
            rg = (l%2)==1? mid+1:mid;
            for(int i=0; i<mid; i++) DATA[(str[i]-'a')]++;
            for(int i=rg; i<l; i++) DATA[(str[i]-'a')]--;
            bool flag=true;
            for(int i=0; i<27; i++)
            {
                if(DATA[i]!=1) {flag=false; cout<<"NO"<<endl; break;}
            }
            if(flag) cout<<"YES"<<endl;
    }
    return 0;
}
