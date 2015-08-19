#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 105;

struct point
{
	double x,y;
	int flag;
	point(double x = 0,double y = 0):x(x),y(y) {}
	friend point operator - (point p1,point p2)
	{
		return point(p1.x-p2.x,p1.y-p2.y);
	}
}p[maxn];
double dis(point p1,point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}
double dot(point p1,point p2)
{
	return p1.x * p2.y - p2.x * p1.y;
}
int n;
bool cmp(point p1,point p2)
{
	return p1.flag >= p2.flag;
}
int main()
{
//	freopen("in","r",stdin);
	while(scanf("%d",&n),n)
	{
		int s = 0;
		for(int i = 0;i < n;++i)
		{
			scanf("%lf%lf",&p[i].x,&p[i].y);
			p[i].flag = 0;
			if(p[i].y < p[s].y) s = i;
			else if(p[i].y == p[s].y && p[i].x < p[s].x) s = i;
		}
		if(n <= 1)
		{
			printf("0.00\n");
			continue;
		}
		if(n == 2)
		{
			printf("%.2lf\n",dis(p[0],p[1]));
			continue;
		}
	//	printf("%.2lf %.2lf\n",p[s].x,p[s].y);
		p[s].flag = 200;
		while(1)
		{
			int t = 0;
			if(t == s) t++;
			for(int i = 0;i < n;++i)
			if(i != s && i != t)
			{
				if(dot(p[t]-p[s],p[i]-p[s]) < 0) t = i;
				else if(dot(p[t]-p[s],p[i]-p[s]) == 0 && dis(p[i],p[s]) > dis(p[t],p[s])) t = i;
			}
			if(p[t].flag == 200) break;
			p[t].flag = p[s].flag - 1;   //标记为是p[s]的下一个点
			s = t;
		}
		sort(p,p+n,cmp);
		double ans = 0;
		int i;
		for(i = 1;i < n && p[i].flag;++i)
		ans += dis(p[i-1],p[i]);
		ans += dis(p[0],p[i-1]);
		printf("%.2lf\n",ans);
	}
	return 0;
}
