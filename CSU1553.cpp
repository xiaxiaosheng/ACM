// File Name: CSU1553.cpp
// Author: xiaxiaosheng
// Created Time: 2015年04月07日 星期二 16时38分46秒

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
const int maxn  = 10005;
int A[maxn];
multiset<int> st;
multiset<int>::iterator iter;
int main() 
{
//	freopen("in.txt","r",stdin);
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		for(int i = 0;i < n;++i)
			scanf("%d",&A[i]);
		int p1 = 0,p2 = 0;
		st.clear();
		int ans = 0;
		for(int i = 0;i < n;++i)
		{
			st.insert(A[i]);
			p2++;
//			for(iter = st.begin();iter != st.end();++iter)
//				printf("%d ",*iter);
//			printf("   ----%d\n",*(--st.end()) - *(st.begin()));
			while(*(--st.end()) - *(st.begin()) > k)
			{
				iter = st.lower_bound(A[p1]);
				st.erase(iter);
				p1++;
			}
			ans = max(ans,(int)st.size());
		}
		printf("%d\n",ans);
	}
	return 0;
}
