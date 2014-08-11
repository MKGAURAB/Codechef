//Md. Khairullah Gaurab
// One of the foulest problem I have ever solved in codechef. :P
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <utility>

#define fs first
#define sc second

using namespace std;

int main(int argc, const char *argv[])
{
    int test, n, k, p, u, v, f, b;
    vector<pair<int,int> > pairvector;
    bool yes;
    cin>>test;
    for(int i=1; i<=test; i++)
    {
        pairvector.clear();
        yes = true;
        cin>>n>>k>>p;
        for(int j=1; j<=k; j++)
        {
            cin>>u>>v;
            if(u>v) v+=n;
            pairvector.push_back(pair<int,int>(u,v));
            //mp.insert(pair<pair<int,int>,bool>(pair<int,int>(v,u),true));
        }
        for(int j=1; j<=p; j++)
        {
            cin>>u>>v;
            f = ((v+1)%n)==0?n:((v+1)%n);
            b = ((u-1)%n)==0?n:((u-1)%n);
            if(v>f) f+=n;
            if(b>u) u+=n;
            for(int l=0; l<k; l++)
            {
                if(pairvector[l].fs==v and pairvector[l].sc==f)
                {
                    yes = false;
                }
                else
                {
                    if(pairvector[l].fs<=v and pairvector[l].sc>=f)
                    {
                        yes = false;
                    }
                }
                if(pairvector[l].fs==b and pairvector[l].sc==u)
                {
                    yes = false;
                }
                else
                {
                    if(pairvector[l].fs<=b and pairvector[l].sc>=u)
                    {
                        yes = false;
                    }
                }

            }
        }
        if(yes) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
