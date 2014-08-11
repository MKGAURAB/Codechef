#include<iostream>
#include<cstdio>
#include<math.h>
#include<limits.h>
#include<algorithm>
#define SZ 100005
using namespace std;
int GetMid(int l, int r)
{
    return l + (r-l)/2;
}
int RMQUtil(int *st,int ss, int se, int qs, int qe, int index)
{
    if(qs<=ss&&qe>=se) return st[index];
    if(se<qs||ss>qe) return INT_MAX;
    int mid = GetMid(ss,se);
    return min(RMQUtil(st,ss,mid,qs,qe,(2*index+1)),RMQUtil(st,mid+1,se,qs,qe,(2*index+2)));
}
int RMQMUtil(int *st,int ss, int se, int qs, int qe, int index)
{
    if(qs<=ss&&qe>=se) return st[index];
    if(se<qs||ss>qe) return -INT_MAX;
    int mid = GetMid(ss,se);
    return max(RMQMUtil(st,ss,mid,qs,qe,(2*index+1)),RMQMUtil(st,mid+1,se,qs,qe,(2*index+2)));
}
int RMQ(int *st, int n, int qs, int qe)
{
    if(qs<0||qe>n-1||qs>qe);
//    {
//        cout<<"INVALID INPUT"<<endl;
//        return -1;
//    }
    return RMQUtil(st, 0, n-1, qs, qe, 0);
}
int RMQM(int *st, int n, int qs, int qe)
{
    if(qs<0||qe>n-1||qs>qe);
//    {
//        cout<<"INVALID INPUT"<<endl;
//        return -1;
//    }
    return RMQMUtil(st, 0, n-1, qs, qe, 0);
}
int ConstructSTUtil(int arr[], int ss, int se, int *st, int si)
{
    if(ss==se)
    {
        st[si]=arr[ss];
        return arr[ss];
    }
    int mid = GetMid(ss,se);
    st[si] = min(ConstructSTUtil(arr, ss, mid, st, (2*si+1)),ConstructSTUtil(arr, mid+1, se, st, (2*si+2)));
    return st[si];
}
int ConstructSTMUtil(int arr[], int ss, int se, int *st, int si)
{
    if(ss==se)
    {
        st[si]=arr[ss];
        return arr[ss];
    }
    int mid = GetMid(ss,se);
    st[si] = max(ConstructSTMUtil(arr, ss, mid, st, (2*si+1)),ConstructSTMUtil(arr, mid+1, se, st, (2*si+2)));
    return st[si];
}
int *ConstructST(int arr[], int n)
{
    int X = (int)(ceil(log2(n)));
    int max_size = 2*((int)pow(2,X))-1;
    int *st = new int[max_size];
    ConstructSTUtil(arr, 0, n-1, st, 0);
    return st;
}
int *ConstructSTM(int arr[], int n)
{
    int X = (int)(ceil(log2(n)));
    int max_size = 2*((int)pow(2,X))-1;
    int *st = new int[max_size];
    ConstructSTMUtil(arr, 0, n-1, st, 0);
    return st;
}
int main()
{
    int DATA[SZ];
    int N, Q;
    cin>>N;
    for(int i=0; i<N; i++) cin>>DATA[i];
    int *st = ConstructST(DATA, N);
    int *st1 = ConstructSTM(DATA, N);
    cin>>Q;
    while(Q--)
    {
        int qs, qe;
        cin>>qs>>qe;
        double qq, qqm, ql, qr;

        qq = (double)RMQ(st, N, qs, qe);
        qqm = (double)RMQM(st1, N, qs, qe);
        ql = (double)RMQM(st1, N, 0,qs-1);
        qr = (double)RMQM(st1, N, qe+1, N-1);
        qqm = (qqm-qq)/2;
        qq = qq + max(max(qqm,ql),max(ql,qr));
        printf("%.1lf\n", qq);
    }
    return 0;
}
