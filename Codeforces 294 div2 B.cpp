#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 100006;
int n,A[maxn],B[maxn],C[maxn];
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(int i = 0;i < n;++i)
		scanf("%d",&A[i]);
		for(int i = 0;i < n-1;++i)
		scanf("%d",&B[i]);
		for(int i = 0;i < n-2;++i)
		scanf("%d",&C[i]);
		B[n-1] = 0;
		C[n-2] = C[n-1] = 0;
		sort(A,A+n);
		sort(B,B+(n-1));
		sort(C,C+(n-2));
		for(int i = 0;i < n;++i)
		if(A[i] != B[i])
		{
			printf("%d\n",A[i]);
			break;
		}
		for(int i = 0;i < n-1;++i)
		if(B[i] != C[i])
		{
			printf("%d\n",B[i]);
			break;
		}
	}
	return 0;
}
