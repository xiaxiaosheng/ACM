#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
const double eps = 1e-9;
struct point
{
	double x,y;
};

double dis(point p1,point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}
double Fabs(double d)
{
	if(d > 0) return d;
	return -1.0 * d;
}
int main()
{
	point p1,p2;
	double r;
	while(scanf("%lf%lf%lf%lf%lf",&r,&p1.x,&p1.y,&p2.x,&p2.y)!=EOF)
	{
		double len = dis(p1,p2);
		int ans = (int) (len / (2.0*r) + eps);
		if(Fabs(2.0*r*ans-len) > 0) ans++;
		printf("%d\n",ans);
	}
	return 0;
}
		
