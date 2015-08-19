#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,visit[55][55];
char str[55][55];
int is_cir;
int _x[4] = {0,1,0,-1};
int _y[4] = {1,0,-1,0};

void dfs(int x,int y,int deep)
{
	if(is_cir) return ;
	visit[x][y] = deep;
	for(int i = 0;i < 4;++i)
	{
		int xx = x + _x[i],yy = y + _y[i];
		if(xx < 0 || yy < 0 || xx >= n || yy >= m) continue;   //超出范围了 
		if(str[x][y] != str[xx][yy]) continue;   //不一样的颜色
		if(visit[xx][yy] > 0)
		{
			if(abs(visit[xx][yy]-visit[x][y]) > 1)
			{
				is_cir = 1;
				return ;
			}
			else continue;
		}
		dfs(xx,yy,deep+1);
	}
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i = 0;i < n;++i)
		scanf("%s",str[i]);
		memset(visit,0,sizeof(visit));
		int flag = 0;
		for(int i = 0;flag == 0 && i < n;++i)
		for(int j = 0;flag == 0 && j < m;++j)
		if(!visit[i][j])
		{
			is_cir = 0;
			dfs(i,j,1);  //参数依次是坐标，第一个点的位置，深度 
			if(is_cir) flag = 1;   //有环 
		}
		printf(flag? "Yes\n":"No\n");
	}
	return 0;
}	
