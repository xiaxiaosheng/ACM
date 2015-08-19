// File Name: CSU.cpp
// Author: xiaxiaosheng
// Created Time: 2015年04月07日 星期二 14时35分47秒

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
const int maxn = 10005;
vector<int> ve;
vector<int>::iterator iter;
int A[maxn];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i = 1;i <= n;++i)
			scanf("%d",&A[i]);
		ve.clear();
		ve.push_back(n);
		if(A[n] > 0)
		{
			puts("No solution");
			continue;
		}
		int flag = 1;
		for(int i = n-1;i >= 1;--i)
		{
			if(A[i] > ve.size())   //无解，直接退出
			{
				flag = 0;
				break;
			}
			iter = ve.begin();
			ve.insert(iter+A[i],i);
		}
		if(!flag)
		{
			puts("No solution");
			continue;
		}
		for(int i = 0;i < ve.size();++i)
			printf(i == ve.size()-1? "%d\n":"%d ",ve[i]);
	}
	return 0;
}
