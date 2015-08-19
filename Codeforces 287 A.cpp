#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
struct node
{
	int a,b;
}A[105];
bool cmp(node a,node b)
{
	return a.a < b.a;
}
int main()
{
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		for(int i = 0;i < n;++i)
		{
			scanf("%d",&A[i].a);
			A[i].b = i;
		}
		sort(A,A+n,cmp);
		int tot = 0,ans = 0;
		for(int i = 0;i < n;++i)
		{
			tot += A[i].a;
			if(tot > k) break;
			ans++;
		}
		printf("%d\n",ans);
		for(int i = 0;i < ans;++i)
		printf(i == ans-1? "%d\n":"%d ",A[i].b+1);
	}
	return 0;
}
