// File Name: HDU1426.cpp
// Author: xiaxiaosheng
// Created Time: 2015年04月08日 星期三 16时37分08秒

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
#include<deque>
using namespace std;

int mat[10][10],num,isend;
struct point
{
	point(int x = 0,int y = 0):x(x),y(y){}
	int x,y;
}p[90];
vector<int> ve[90];
vector<int>::iterator iter;
int check(point p,int d)
{
	for(int i = 0;i < 9;++i)
	{
		if(i != p.y && mat[p.x][i] == d) return 0;
		if(i != p.x && mat[i][p.y] == d) return 0;
	}
	int sx = 3 * (p.x / 3),sy = 3 * (p.y / 3);
	for(int i = sx;i < sx + 3;++i)
		for(int j = sy;j < sy + 3;++j)
			if(!(i == p.x && j == p.y) && mat[i][j] == d)
				return 0;
	return 1;
}
void dfs(int deep)
{
	if(isend) return ;
	if(deep == num)
	{
		isend = 1;
		for(int i = 0;i < 9;++i)   //把答案保存下来
			for(int j = 0;j < 9;++j)
				printf(j == 8? "%d\n":"%d ",mat[i][j]);
		return ;
	}
	for(int i = 0;isend == 0 && i < ve[deep].size();++i)
	{
		if(check(p[deep],ve[deep][i]))
		{
			mat[p[deep].x][p[deep].y] = ve[deep][i];
			dfs(deep + 1);
			mat[p[deep].x][p[deep].y] = 0;
		}
	}
}
int main()
{
//	freopen("in.txt","r",stdin);
	int flag = 0;
	char str[5];
	while(scanf("%s",str)!=EOF)
	{
		if(flag) puts("");  //两个测试之间有空行
		flag = 1;
		memset(mat,0,sizeof(mat));
		int f = 0;
		if(str[0] != '?')
			mat[0][0] = atoi(str);
		else p[f++] = point(0,0);
		for(int i = 1;i < 81;++i)
		{
			scanf("%s",str);
			if(str[0] != '?')
				mat[i / 9][i % 9] = atoi(str);
			else p[f++] = point(i / 9,i % 9);
		}
		num = f;
		for(int i = 0;i < f;++i)
			ve[i].clear();
		for(int i = 0;i < f;++i)      //预处理，剪枝
			for(int j = 1;j <= 9;++j)
				if(check(p[i],j))     //去掉预处理试试
					ve[i].push_back(j);
		isend = 0;
		dfs(0);
	//	for(int i = 0;i < 9;++i)
	//		for(int j = 0;j < 9;++j)
	//			printf(j == 8? "%d\n":"%d ",ans[i][j]);
	}
	return 0;
}
