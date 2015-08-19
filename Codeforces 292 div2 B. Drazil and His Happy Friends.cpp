#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n,m,b,g,A[110],B[110];
int Max(int a,int b)
{
	return a > b? a:b;
}
int check(int a,int *A,int b,int *B)
{
	for(int i = 0;i < a;++i)
	if(A[i] == 0)
	return 0;
	for(int i = 0;i < b;++i)
	if(B[i] == 0)
	return 0;
	return 1;
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		scanf("%d",&b);
		int t;
		for(int i = 0;i < b;++i)
		{
			scanf("%d",&t);
			A[t] = 1;
		}
		scanf("%d",&g);
		for(int i = 0;i < g;++i)
		{
			scanf("%d",&t);
			B[t] = 1;
		}
		for(int i = 0;i <= 10000;++i)
		{
			int x = i % n;
			int y = i % m;
			A[x] = Max(A[x],B[y]);
			B[y]= Max(A[x],B[y]);
		}
		printf(check(n,A,m,B)? "Yes\n":"No\n");
	}
	return 0;
}			
