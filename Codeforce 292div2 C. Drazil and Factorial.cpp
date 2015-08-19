#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,A[100];
char str[20];
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%s",str);
		int f = 0;
		for(int i = 0;i < n;++i)
		{
			if(str[i] == '4')
			{
				A[f++] = 3;
				A[f++] = 2;
				A[f++] = 2;
			}
			else if(str[i] == '6')
			{
				A[f++] = 5;
				A[f++] = 3;
			}
			else if(str[i] == '8')
			{
				A[f++] = 7;
				A[f++] = 2;
				A[f++] = 2;
				A[f++] = 2;
			}
			else if(str[i] == '9')
			{
				A[f++] = 7;
				A[f++] = 3;
				A[f++] = 3;
				A[f++] = 2;
			}
			else
			{
				if(str[i]-'0' > 1)
					A[f++] = str[i] - '0';
			}
		}
		sort(A,A+f);
		for(int i = f-1;i >= 0;--i)
		printf("%d",A[i]);
		puts("");
	}
	return 0;
}
