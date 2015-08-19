#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 1005;
const double eps = 1e-6;
struct point
{
	double x,y;
	point(double x = 0,double y = 0):x(x),y(y) {}
	inline friend point operator + (point p1,point p2)
	{
		return point(p1.x+p2.x,p1.y+p2.y);
	}
	inline friend point operator - (point p1,point p2)
	{
		return point(p1.x-p2.x,p1.y-p2.y);
	}
}pos[maxn];
struct line
{
	point s,e;
	int flag;
}L[maxn];
int pre[maxn];
int find(int d)
{
	return pre[d] == d? d:pre[d] = find(pre[d]);
}
inline double dot(point p1,point p2)    //求叉积
{
	return p1.x*p2.y - p2.x*p1.y;
}
int judge(point p1,point p2,point p3,point p4)    //判断线段没有没交点
{
	double temp1 = dot(p1-p3,p4-p3) * dot(p2-p3,p4-p3);
	double temp2 = dot(p3-p1,p2-p1) * dot(p4-p1,p2-p1);
	if((temp1 < 0 || fabs(temp1) < eps) && (temp2 < 0 || fabs(temp2) < eps)) return 1;
	return 0;
}
int T,n,m;
void push(line t,line* L,int m)
{
	for(int i = 1;i < m;++i)
	if(judge(L[i].s,L[i].e,t.s,t.e))
	{
		pre[find(t.flag)] = find(L[i].flag);
	//	break;
	}
	L[m] = t;
}
int query(int k)
{
	int temp = find(k),ans = 0;
	for(int i = 1;i <= m;++i)
	if(find(i) == temp)
	ans++;
	return ans;
}
int main()
{
//	freopen("in","r",stdin);
	double x1,y1,x2,y2;
	scanf("%d",&T);
	for(int l = 0;l < T;++l)
	{
		if(l) puts("");
		scanf("%d",&n);
		for(int i = 0;i <= 1000;++i)  //初始化并查集
		pre[i] = i;
		char oper[5];
		m = 0;   //初始化当前线段的数量
		while(n--)
		{
			scanf("%s",oper);
			if(oper[0] == 'P')
			{
				line temp;
				scanf("%lf%lf%lf%lf",&temp.s.x,&temp.s.y,&temp.e.x,&temp.e.y);
				temp.flag = ++m;
				push(temp,L,m);
			}
			else if(oper[0] == 'Q')
			{
				int k;
				scanf("%d",&k);
				printf("%d\n",query(k));
			}
		}
//		for(int i = 1;i <= m;++i)
//		{
//			for(int j = 1;j <= m;++j)
//			printf(judge(L[i].s,L[i].e,L[j].s,L[j].e)? "1 ":"0 ");
//			printf("\n");
//		}
	}
	return 0;
}
