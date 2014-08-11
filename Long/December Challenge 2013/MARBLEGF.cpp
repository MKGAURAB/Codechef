//Md. Khairullah Gaurab
//CSE, SUST
//20th Batch

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define SZ 1000000
using namespace std;

long long int stree[SZ*4];
long long int DATA[SZ+5];
void build(int root, int beg, int end)
{
	if(beg==end)
	{
		stree[root] = DATA[beg];
		return;
	}
	int left = root<<1;
	int right = left +1;
	int mid = (beg+end)>>1;
	build(left,beg,mid);
	build(right,mid+1,end);
	stree[root] = stree[left] + stree[right];
}
void update(int root, int beg, int end, int pos, int val)
{
	if(beg==pos && pos==end)
	{
		stree[root] += val;
		return;
	}
	int left = root<<1;
	int right = left +1;
	int mid = (beg+end)>>1;

	if(pos<=mid) update(left,beg,mid,pos,val);
	else update(right,mid+1,end,pos,val);

	stree[root] = stree[left] + stree[right];
}
long long query(int root, int beg, int end, int i, int j)
{
	if(i==beg && j==end) return stree[root];
	int left = root<<1;
	int right = left +1;
	int mid = (beg+end)>>1;
	if(j<=mid)
	{
		return query(left,beg,mid,i,j);
	}
	else if(i>mid)
	{
		return query(right,mid+1,end,i,j);
	}
	else return query(left,beg,mid,i,mid) + query(right,mid+1,end,mid+1,j);
}
int main(int argc, char const *argv[])
{
	int N, Q;
	char cmd;
	scanf("%d %d",&N, &Q);
	for (int i = 1; i <=N; ++i)
	{
		scanf("%lld",&DATA[i]);
	}

	build(1,1,N);

	for (int i = 0; i <Q; ++i)
	{
		int f, t;
		scanf(" %c%d%d",&cmd, &f, &t);
		if(cmd=='S')
		{
			printf("%lld\n", query(1,1,N,f+1,t+1));
			//printf("0\n");
		}
		else if(cmd=='G')
		{
			update(1,1,N,f+1,t);
		}
		else if(cmd=='T')
		{
			update(1,1,N,f+1,(-1*t));
		}
	}
	return 0;
}