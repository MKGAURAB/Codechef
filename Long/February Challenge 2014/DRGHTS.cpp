#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
typedef long long int ll;
const int MAX = 50005;

vector<ll> G[MAX];
bool flag[MAX], I[MAX], used[MAX];
ll one;

int DFS(int src)
{
    int len, v;
    used[src] = true;
    if(flag[src])
    {
        one++;
    }
    ll temp = 0LL;
    len = G[src].size();
    for(int i=0; i<len; ++i)
    {
        v = G[src][i];
        if(!used[v])
        {
            temp+=DFS(v);
        }
    }
    if(temp==0)
    {
        if(one>1 and flag[src])
        {
            I[src] = true;
            return 1;
        }
        else{
            I[src] = false;
            return 0;
        }
    }
    else{
        I[src] = true;
        return 1;
    }

}
int main(int arc, const char *argv[])
{
    ios::sync_with_stdio(false);
    ll N, M, x, y;
    cin>>N>>M;
    for(int i=1; i<=N; ++i)
    {
        cin>>x;
        if(x) flag[i] = true;
        else flag[i] = false;
    }
    for(int i=0; i<M; ++i)
    {
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    ll furik, rubik;
    furik = rubik = 0LL;
    memset(used,false,sizeof(used));
    memset(I,false,sizeof(I));
    for(int i=1; i<=N; ++i)
    {
        if(!used[i] and flag[i])
        {
            one = 0LL;
            DFS(i);
            furik += ((one*(one-1))/2);
        }
    }
    for(int i=1; i<=N; i++)
    {
        if(I[i]) rubik++;
    }
    cout<<furik<<" "<<rubik<<endl;
    return 0;
}
