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
	point(double x = 0,double y = 0):x(x),y(y) {}
	friend  point operator + (point p1,point p2)
	{
		return point(p1.x+p2.x,p1.y+p2.y);
	}
	friend  point operator - (point p1,point p2)
	{
		return point(p1.x-p2.x,p1.y-p2.y);
	}
	
}p[maxn],res[maxn];
double dis(point p1,point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}
double dot(point p1,point p2)
{
	return p1.x*p2.y - p2.x*p1.y;
}
bool cmp(point p1,point p2)
{
	if(p1.y == p2.y) return p1.x < p2.x;
	return p1.y < p2.y;
}
int graham(point* p,int n,point* res)
{
	sort(p,p+n,cmp);
	res[0] = p[0];
	res[1] = p[1];
	res[2] = p[2];
	int top = 1,len;
	for(int i = 2;i < n;++i)
	{
		while(top && dot(p[i]-res[top-1],res[top]-res[top-1]) >= 0) top--;
		res[++top] = p[i];
	}
	len = top;
	for(int i = n-1;i >= 0;--i)
	{
		while(top != len && dot(p[i]-res[top-1],res[top]-res[top-1]) >= 0) top--;
		res[++top] = p[i];
	}
	return top;
}
			
int main()
{
//	freopen("in.txt","r",stdin);
	int n;
	while(scanf("%d",&n),n)
	{
		for(int i = 0;i < n;++i)
		scanf("%lf%lf",&p[i].x,&p[i].y);
		if(n == 1)
		{
			printf("0.00\n");
			continue;
		}
		if(n == 2)
		{
			printf("%.2lf\n",dis(p[0],p[1]));
			continue;
		}
		int m = graham(p,n,res);
		double tot = 0;
		for(int i = 1;i <= m;++i)
		tot += dis(res[i-1],res[i]);
		printf("%.2lf\n",tot);
	}
	return 0;
}
