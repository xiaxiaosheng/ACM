#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps = 1e-8,PI = acos(-1.0);

struct point
{
	double x,y;
	point(double x = 0,double y = 0) :x(x),y(y){}
	double len()
	{
		return sqrt(x*x+y*y+eps);
	}
};
inline double dis(point p1,point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)+eps);
}
double get_dis(point v,point p)
{
	if(fabs(v.x*p.y - p.x*v.y) < eps) return 0;
	double si = (v.x*p.y-p.x*v.y)/dis(point(0,0),v)/p.len();
	return p.len() * fabs(si);
}
int judge(point p,point v)
{
	point temp;
	temp.x = -1 * p.x;
	temp.y = -1 * p.y;
	return (temp.x*v.x+temp.y*v.y < 0) || (fabs(temp.x*v.x+temp.y*v.y) <eps);
}
int main()
{
//	freopen("in.txt","r",stdin);
	double Rm,R,r;
	point p,v;
	while(scanf("%lf%lf%lf%lf%lf%lf%lf",&Rm,&R,&r,&p.x,&p.y,&v.x,&v.y)!=EOF)
	{
		if(judge(p,v))
		{
			printf("0.0000\n");
			continue;
		}
		double V = v.len();
		double D = get_dis(v,p);     //�õ�Ӳ�ҵ���ԭ����˶�·�ߵľ���
//		printf("%.3lf\n",D);
		double ans = 0;
		if(D < Rm+r)    //����ײ���ӣ������������Ŀ�ķ���Υ���˳���һֱwa������ 
		{
			double l = sqrt((R+r)*(R+r)-D*D+eps) - sqrt((Rm+r)*(Rm+r)-D*D+eps);  //����Ȧ��ʼ����ײ�߹��ľ���
			ans += (l / V);
		//	ans += (R - Rm) / V;
		}
		else if(D > Rm+r && D < R + r)
		{
			double t = sqrt((R+r)*(R+r) - D*D+eps) / V;
		}
		else     //�������Բ�η�Χ 
		{
			printf("0.00000\n");
			continue;
		} 
		printf("%lf\n",2*ans+eps);
	}
	return 0;
}		
