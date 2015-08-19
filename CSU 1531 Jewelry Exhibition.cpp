#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int M[505],visit[505];
vector<int> ve[505];

int match(int p)
{
	for(int i = 0;i < ve[p].size();++i)
		if(0 == visit[ve[p][i]])
		{
			visit[ve[p][i]] = 1;
			if(0 == M[ve[p][i]] || match(M[ve[p][i]]))
			{
				M[ve[p][i]] = p;
				return 1;
			}
		}
	return 0;
}
int main()
{
//	freopen("in.txt","r",stdin);
	int T,n,m,k;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		int L = max(n,m);
		double ta,tb;
		memset(M,0,sizeof(M));
		for(int i = 0;i <= L;++i)
			ve[i].clear();
		for(int i = 0;i < k;++i)
		{
			scanf("%lf%lf",&ta,&tb);
			ve[(int)ta+1].push_back((int)tb+1);
		}
		int ans = 0;
		for(int i = 1;i <= L;++i)
		{
			memset(visit,0,sizeof(visit));
			if(match(i))
				ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
