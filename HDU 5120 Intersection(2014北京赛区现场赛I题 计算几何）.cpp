#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const double PI = acos(-1.0),eps = 1e-9;
struct point
{
    double x,y;
};
struct circle
{
    point c;
    double r;
};

circle  A,a,B,b;
double dis(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double dis_line(point p,double a,double b,double c)
{
    return(fabs(a*p.x+b*p.y+c)/sqrt(a*a+b*b));
}
double get_in(circle x,circle y)     //求两 园交集的面积
{
    if(dis(x.c,y.c) < (x.r-y.r) || fabs(dis(x.c,y.c) - (x.r-y.r)) < eps) return PI * y.r*y.r;
    if(dis(x.c,y.c) > x.r+y.r || fabs(dis(x.c,y.c)-(x.r+y.r)) < eps) return 0;
    double a = 2.0 * (x.c.x - y.c.x),b = 2.0 * (x.c.y-y.c.y),c = y.c.x*y.c.x-x.c.x*x.c.x + y.c.y*y.c.y-x.c.y*x.c.y+x.r*x.r-y.r*y.r;
    double l1 = dis_line(x.c,a,b,c);
    double co1 = acos(l1 / x.r) * 2.0;
    double s1 = PI * x.r*x.r*(co1/PI/2.0) - (0.5*x.r*x.r*sin(co1));
    double l2 = dis_line(y.c,a,b,c);
    double co2 = acos(l2 / y.r) * 2.0,s2;
	if((a*x.c.x+b*x.c.y+c) * (a*y.c.x+b*y.c.y+c) <= 0)     //两圆心在园交点的两侧
    s2 = PI * y.r*y.r*(co2 / PI/2.0) - (0.5*y.r*y.r*sin(co2));
    else s2 = PI * y.r*y.r*((2.0*PI-co2)/(2.0*PI)) + (0.5*y.r*y.r*sin(co2));
	return s1+s2;
}


int main()
{
 //   freopen("in","r",stdin);
    int T,kase = 1;
    scanf("%d",&T);
    while(T--)
    {
        double r1,r2;
        scanf("%lf%lf",&r1,&r2);
        scanf("%lf%lf",&A.c.x,&A.c.y);
        a = A;
        scanf("%lf%lf",&B.c.x,&B.c.y);
        b = B;
        A.r = B.r = r2;
        a.r = b.r = r1;
        double ans = get_in(A,B);
  //      printf("%lf\n",get_in(A,B));
        ans -= (2.0 * get_in(A,b));
    //    printf("%lf\n",get_in(A,b));
        ans += get_in(a,b);
   //     printf("%lf\n",get_in(a,b));
        printf("Case #%d: %lf\n",kase++,ans+eps);
    }
    return 0;
}
