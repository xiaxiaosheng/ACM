#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100005;

char str[maxn];
int A[maxn];

int main()
{
	while(scanf("%s",str)!=EOF)
	{
		int len = strlen(str);
		for(int i = 0;i < len;++i)
		A[i] = str[i] - '0';
		int flag = 0;
		for(int i = 0;i < len-1;++i)
		if(!(A[i] & 1) && A[i] < A[len-1])
		{
			flag = 1;
			swap(A[i],A[len-1]);
			break;
		}
		if(flag == 0)
		for(int i = len-2;i >= 0;--i)
		if(!(A[i] & 1))
		{
			flag = 1;
			swap(A[i],A[len-1]);
			break;
		}
		if(A[len-1] & 1) printf("-1\n");
		else
		{
			for(int i = 0;i < len;++i)
			printf("%d",A[i]);
			puts("");
		}
	}	
	return 0;
}
