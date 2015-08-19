#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int ans = 0;
		while((n + m) >= 3 && n > 0 && m > 0)
		{
			if(n > m)
			{
				n -= 2;
				m -= 1;
				ans++;
			}
			else
			{
				n  -= 1;
				m -= 2;
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
