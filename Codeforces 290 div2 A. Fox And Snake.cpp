#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n,m;
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int f1 = 0,f2 = 0;
		while(n--)
		{
			if(f1 & 1)
			{
				if(f2 == 1) printf("#");
				for(int i = 0;i < m-1;++i)
				printf(".");
				if(f2 == 0) puts("#");
				else puts("");
				f2 = !f2;
			}
			else
			{
				for(int i = 0;i < m;++i)
				printf("#");
				puts("");
			}
			f1 = !f1;
		}
	}
	return 0;
}
