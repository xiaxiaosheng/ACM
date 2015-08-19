#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct node
{
	char name[55];
	int w,r,t;
}men[205];
bool cmp(node a,node b)
{
	if(a.w != b.w) return a.w > b.w;
	else if(a.w == b.w)
	{
		if(strcmp(a.name,b.name) < 0) return 1;
		else return 0;
	}
}

int find(int n,char* str)
{
	for(int i = 0;i < n;++i)
	if(!strcmp(men[i].name,str))
	return i;
	return 0;
}
int main()
{
//	freopen("in.txt","r",stdin);
	int n,m;
	char str[55];
	while(scanf("%d",&n),n)
	{
		for(int i = 0;i < n;++i)
		{
			scanf("%s%d",men[i].name,&men[i].w);
			men[i].t = 1;
		}
		sort(men,men+n,cmp);
		for(int i = 0;i < n;++i)
		printf("%s %d\n",men[i].name,men[i].w);
		for(int i = 0;i < n;++i)
		{
			int tt = 0;
			for(int j = 0;j < i;++j)
			if(men[j].w > men[i].w) tt++;
			men[i].r = tt;
		}
		for(int i = 0;i < n;++i)
		for(int j = 0;j < i;++j)
		if(men[i].w == men[j].w)
		men[i].t++;
		scanf("%d",&m);
		while(m--)
		{
			scanf("%s",str);
			int l = find(n,str);
			if(men[l].t <= 1) printf("%d\n",men[l].r+1);
			else printf("%d %d\n",men[l].r+1,men[l].t);
		}
	}
	return 0;
}
