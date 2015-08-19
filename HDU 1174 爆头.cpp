#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const double PI = acos(-1.0);
struct Point
{
    double x,y,z;
    Point(double a = 0,double b = 0,double c = 0) :x(a),y(b),z(c) {}
    friend Point operator + (Point a,Point b)
    {
        return Point(a.x+b.x,a.y+b.y,a.z+b.z);
    }
    friend Point operator - (Point a,Point b)
    {
        return Point(a.x-b.x,a.y-b.y,a.z-b.z);
    }
};
double length(Point a)
{
    return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
}
int main()
{
 //   freopen("in","r",stdin);
    int T;
    double h1,r1,h2,r2;
    Point p1,p2,p;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf%lf%lf%lf%lf",&h1,&r1,&p1.x,&p1.y,&p1.z);
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&h2,&r2,&p2.x,&p2.y,&p2.z,&p.x,&p.y,&p.z);
        Point  o1 = p2,o2 = p1;
        o2.z += (h1 - r1);
        o1.z += (0.9 * h2 - r2);
        Point oo = o2 - o1;
        double temp = (oo.x*p.x + oo.y * p.y + oo.z * p.z) / length(oo) / length(p);
        double angle = acos(temp);    //求夹角
        if(angle <= 0)
        {
            puts("NO");
            continue;
        }
        double D = sin(angle) * length(oo);
        printf(D <= r1? "YES\n":"NO\n");
    }
    return 0;
}
