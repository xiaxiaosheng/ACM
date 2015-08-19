// File Name: CSU1550.cpp
// Author: xiaxiaosheng
// Created Time: 2015年04月07日 星期二 17时32分28秒

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
const int maxn = 200005;
char str[maxn];
int A[30],B[30],t1[20],t2[30],tot1,tot2,n;
int get(int p)
{
	if(A[p] > 0)
	{
		if(tot1 < n)
		{
			A[p]--;
			t1[p]++;
			tot1++;
			return 1;
		}
		else
		{
			for(int i = 0;i < 26;++i)
			{
				if(t1[i] > 0 && B[i])
				{
					t1[i]--;
					A[i]++;
					tot1--;
					B[i]--;
					t2[i]++;
					tot2++;
					return get(p);
				}
			}
		}
	}
	if(B[p] > 0)
	{
		if(tot2 < n)
		{
			t2[p]++;
			tot2++;
			B[p]--;
			return 1;
		}
		else
		{
			for(int i = 0;i < 26;++i)
			{
				if(t2[i] > 0 && A[i])
				{
					t2[i]--;
					B[i]++;
					tot2--;
					t1[i]++;
					A[i]--;
					tot1++;
					return get(p);
				}
			}
		}
	}
	return 0;
}
int main()
{
//	freopen("in.txt","r",stdin);
	while(scanf("%s",str)!=EOF)
	{
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		int len = strlen(str);
		n = len / 2;
		for(int i = 0;i < len;++i)
			A[str[i]-'A']++;
		scanf("%s",str);
		for(int i = 0;i < len;++i)
			B[str[i]-'A']++;
		scanf("%s",str);
		memset(t1,0,sizeof(t1));
		memset(t2,0,sizeof(t2));
		tot1 = tot2 = 0;
		int flag = 1;
		for(int i = 0;i < len;++i)	
			if(get(str[i]-'A')) continue;
			else
			{
				flag = 0;
				break;
			}
		printf(flag? "YES\n":"NO\n");
	}
	return 0;
}
