// File Name: HDU3743.cpp
// Author: xiaxiaosheng
// Created Time: 2015年03月09日 星期一 21时54分45秒

#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>

using namespace std;
typedef __int64 INT;
const int maxn = 10e6+10;

int n,A[maxn],temp[maxn];
INT ans;
void merger(int *A,int s,int mid,int e)
{
	int k = 0,i = s,j = mid+1;
	while(i <= mid && j <= e)
	{
		if(A[i] < A[j])
			temp[k++] = A[i++];
		else
		{
			ans += (mid-i+1);
			temp[k++] = A[j++];
		}
	}
	while(i <= mid) temp[k++] = A[i++];
	while(j <= e) temp[k++] = A[j++];
	for(int i = 0;i < k;++i)
		A[s+i] = temp[i];
}
void mergersort(int *A,int s,int e)
{
	if(s < e)
	{
		int mid = (s + e) / 2;
		mergersort(A,s,mid);
		mergersort(A,mid+1,e);
		merger(A,s,mid,e);
	}

}
int main(){
	while(scanf("%d",&n)!=EOF)
	{
		for(int i = 0;i < n;++i)
			scanf("%d",&A[i]);
		ans = 0;
		mergersort(A,0,n-1);
		printf("%I64d\n",ans);
	}
	return 0;
}
