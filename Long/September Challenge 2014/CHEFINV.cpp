#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <algorithm>
    
    
#define sf scanf
#define pf printf
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define all(a) (a.begin(),a.end())
#define REP(i,a,b) for(int i=a; i<=b; ++i)
#define REPR(i,a,b) for(int i=b; i>=a; --i)
#define mp(a,b) make_pair(a,b)
#define fs first
#define sc second
#define unq(vec) stable_sort(vec.begin(),vec.end());\
                     vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())));
    
using namespace std;
    
const int inf = 2000000000;
const int SZ = 200000 + 7;

//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};    

typedef long long Long;
typedef double dd;
Long data[SZ], data1[SZ];

Long  _mergeSort(Long arr[], Long temp[], Long left, Long right);
Long merge(Long arr[], Long temp[], Long left, Long mid, Long right);
  
/* This function sorts the input array and returns the
   number of inversions in the array */
Long mergeSort(Long arr[], Long array_size)
{
    Long *temp = (Long *)malloc(sizeof(Long)*array_size);
    return _mergeSort(arr, temp, 0, array_size - 1);
}
  
/* An auxiliary recursive function that sorts the input array and
  returns the number of inversions in the array. */
Long _mergeSort(Long arr[], Long temp[], Long left, Long right)
{
  Long mid, inv_count = 0;
  if (right > left)
  {
    /* Divide the array into two parts and call _mergeSortAndCountInv()
       for each of the parts */
    mid = (right + left)/2;
  
    /* Inversion count will be sum of inversions in left-part, right-part
      and number of inversions in merging */
    inv_count  = _mergeSort(arr, temp, left, mid);
    inv_count += _mergeSort(arr, temp, mid+1, right);
  
    /*Merge the two parts*/
    inv_count += merge(arr, temp, left, mid+1, right);
  }
  return inv_count;
}
  
/* This funt merges two sorted arrays and returns inversion count in
   the arrays.*/
Long merge(Long arr[], Long temp[], Long left, Long mid, Long right)
{
  Long i, j, k;
  Long inv_count = 0;
  
  i = left; /* i is index for left subarray*/
  j = mid;  /* i is index for right subarray*/
  k = left; /* i is index for resultant merged subarray*/
  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];
  
     /*this is tricky -- see above explanation/diagram for merge()*/
      inv_count = inv_count + (mid - i);
    }
  }
  
  /* Copy the remaining elements of left subarray
   (if there are any) to temp*/
  while (i <= mid - 1)
    temp[k++] = arr[i++];
  
  /* Copy the remaining elements of right subarray
   (if there are any) to temp*/
  while (j <= right)
    temp[k++] = arr[j++];
  
  /*Copy back the merged elements to original array*/
  for (i=left; i <= right; i++)
    arr[i] = temp[i];
  
  return inv_count;
}

    
int main(int argc, const char **argv)
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int N, Q;
    Long u, v;
    sf("%d %d",&N, &Q);
    REP(i,0,(N-1)) sf("%lld",&data1[i]);
    REP(i,0,(Q-1))
    {
    	sf("%lld %lld",&u, &v);
    	u--;
    	v--;
    	copy(data1,data1+N,data);
    	Long tmp = data[u];
    	data[u] = data[v];
    	data[v] = tmp;
    	Long ret = mergeSort(data,N);
    	pf("%lld\n",ret);
    }
    return 0;
}