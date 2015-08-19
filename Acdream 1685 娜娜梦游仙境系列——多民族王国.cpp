// File Name: F.cpp
// Author: xiaxiaosheng
// Created Time: 2015年04月12日 星期日 19时48分39秒

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
const int maxn = 105;

int pre[maxn],flag[maxn],lang[maxn];
int find(int d)
{
	return pre[d] == d? d:(pre[d] = find(pre[d]));
}

int main()
{
//	freopen("in.txt","r",stdin);
	int T,n,m;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i = 0;i <= n;++i)
			pre[i] = i;
		int k,t,ff = 0;
		memset(lang,0,sizeof(lang));
		for(int i = 1;i <= n;++i)
		{
			scanf("%d",&k);
			if(k > 0) ff = 1;
			if(k < 0) continue;
			while(k--)
			{
				scanf("%d",&t);
				if(lang[t] != 0)
				{
					int t1 = find(lang[t]);
					int t2 = find(i);
					if(t1 > t2) swap(t1,t2);	
					pre[t1] = t2;
				}
				lang[t] = i;
			}
		}
		int ans = 0;
		memset(flag,0,sizeof(flag));
		for(int i = 1;i <= n;++i)
			flag[find(i)] = 1;
		for(int i = 1;i <= n;++i)
			ans += flag[i];
		if(ff)
			printf("%d\n",ans-1);
		else printf("%d\n",ans);
	}
	return 0;
}
