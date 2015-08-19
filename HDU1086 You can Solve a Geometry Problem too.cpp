#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 105;
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
}A[maxn],B[maxn];

inline double dot(point p1,point p2)
{
	return p1.x*p2.y - p2.x*p1.y;
}
inline double dis(point p1,point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}
int judge(point p1,point p2,point p3,point p4)
{
	double temp = dot(p3-p1,p2-p1) * dot(p4-p1,p2-p1);
	if(temp < 0 || fabs(temp) < eps) return 1;
	return 0;
}

int main()
{
	freopen("in","r",stdin);
	int n;
	while(scanf("%d",&n),n)
	{
		for(int i = 0;i < n;++i)
		scanf("%lf%lf%lf%lf",&A[i].x,&A[i].y,&B[i].x,&B[i].y);
		int ans = 0;
		for(int i = 0;i < n;++i)
		for(int j = i+1;j < n;++j)
		{
			 if(judge(A[i],B[i],A[j],B[j]) && judge(A[j],B[j],A[i],B[i])) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
