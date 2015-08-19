#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;
const int maxn = 200010;
int n;
struct node
{
	int flag;
	int w,h;
}A[maxn];
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		int tot = 0,m1 = 0,m2 = 0;
		for(int i = 0;i < n;++i)
		{
			scanf("%d%d",&A[i].w,&A[i].h);
			tot += A[i].w;
			if(A[i].h > A[m1].h) m1 = i;
		}
		m2 = n,A[n].h = -1;
		for(int i = 0;i < n;++i)
			if(i != m1 && A[i].h > A[m2].h)
				m2 = i;
		for(int i = 0;i < n;++i)
		{
			if(i != m1)
				printf("%d",(tot-A[i].w) * A[m1].h);
			else printf("%d",(tot-A[i].w)*A[m2].h);
			if(i != n-1)
				printf(" ");
		}
		puts("");
	}
	return 0;
}
