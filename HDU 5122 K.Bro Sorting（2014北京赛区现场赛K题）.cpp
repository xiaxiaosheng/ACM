#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef __int64 INT;
const int maxn = 1e6+5;

int A[maxn];

int main()
{
	int T,n,kase = 1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i = 0;i < n;++i)
		scanf("%d",&A[i]);
		INT ans = 0;
		int M = 0x7fffffff;
		for(int i = n-1;i >= 0;--i)
		{
			if(M < A[i]) ans++;
			M = min(M,A[i]);
		}
		printf("Case #%d: %I64d\n",kase++,ans);
	}
	return 0;
}		
