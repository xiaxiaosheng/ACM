// File Name: CSU1547.cpp
// Author: xiaxiaosheng
// Created Time: 2015年03月29日 星期日 16时30分23秒

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

vector<int> A;
int dp[10005];
int main()
{
//	freopen("in.txt","r",stdin);
	int T,n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int x,y,ans = 0,sum = 0;
		A.clear();
		while(n--)
		{
			scanf("%d%d",&x,&y);
			if(x == 2) ans += y;
			else
			{
				sum += y;
				A.push_back(y);
			}
		}
		memset(dp,0,sizeof(dp));
		dp[0] = 1;
		for(int i = 0;i < A.size();++i)
			for(int j = sum - A[i];j >= 0;--j)
				if(dp[j] == 1)
					dp[j + A[i]] = 1;
		int temp = 0x7fffffff;
//		printf("%d\n",dp[4]);
		for(int i = 0;i <= sum;++i)
			if(dp[i])
				temp = min(temp,max(sum-i,i));
		printf("%d\n",ans+temp);
	}
	return 0;
}
