#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 1e6+5;

struct node
{
	double t,x;
}rec[maxn];
double Max(double a,double b)
{
	return a > b? a : b;
}
bool cmp(node a,node b)
{
	return a.t < b.t;
}
double Fabs(double d)
{
	return d > 0? d:-1.0*d;
}
int main()
{
	int T,n,kase = 1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i = 0;i < n;++i)
		scanf("%lf%lf",&rec[i].t,&rec[i].x);
		sort(rec,rec+n,cmp);
		double ans = 0;
		for(int i = 1;i < n;++i)
		ans = Max(ans,Fabs(rec[i].x-rec[i-1].x) / (rec[i].t - rec[i-1].t));
		printf("Case #%d: %.2lf\n",kase++,ans);
	}
	return 0;
}
