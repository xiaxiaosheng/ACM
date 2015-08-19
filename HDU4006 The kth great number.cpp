// File Name: HDU4006.cpp
// Author: xiaxiaosheng
// Created Time: 2015年06月02日 星期二 09时07分07秒

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
#include<queue>
using namespace std;

struct node
{
	int a;
	node(int t = 0): a(t) {}
	friend bool operator < (node a,node b)
	{
		return a.a > b.a;
	}
};
priority_queue<node> que;
int main()
{
//	freopen("in","r",stdin);
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		char op[3];
		int temp;
		while(!que.empty())
			que.pop();
		while(n--)
		{
			scanf("%s",op);
			if(op[0] == 'I')
			{
				scanf("%d",&temp);
				node t = node(temp);
				que.push(t);
				if(que.size() > k)
					que.pop();
			//	cout<<que.top().a<<endl;
			}
			else
			{
				printf("%d\n",que.top().a);
			}
		}
	}
	return 0;
}
