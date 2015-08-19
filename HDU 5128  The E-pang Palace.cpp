#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps = 1e-9;
struct point
{
	double x,y;
	point(double x = 0,double y = 0): x(x),y(y) {}
	friend point operator - (point a,point b)
	{
		return point(a.x-b.x,a.y-b.y);
	}
}P[35];
struct rect
{
	point p[4];
}R[1000];
double dot(point a,point b)     //叉积
{
	return a.x*b.y - b.x * a.y;
}
int judge_pingxing(point a,point b)
{
	return (fabs(dot(a,b)) < eps);
}
double dis(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int is_trang(point p1,point p2,point p3,point p4)   //判断是不是矩形
{
	point d1 = p1 - p2;
	point d2 = p3 - p4;
	if(judge_pingxing(d1,d2))
	{
		if(p1.x > p2.x) swap(p1,p2);
		if(p3.x > p4.x) swap(p3,p4);
		d1 = p1-p2,d2 = p1-p3;
		point d3 = p1 - p3,d4 = p2 - p4;
//		printf("%.0lf  %.0lf\n",d1.x,d1.y);
//		printf("%.0lf  %.0lf\n",d2.x,d2.y);
	//	printf("%.0lf\n",d1.x*d2.x+d1.y*d2.y);
		if(fabs(d1.x*d2.x+d1.y*d2.y) < eps && judge_pingxing(d3,d4)) return 1;
	}
	return 0;
}
int make(int n)     //构造矩形
{
	int tot = 0;
	for(int i = 0;i < n;++i)
	for(int j = i+1;j < n;++j)
	for(int k = j+1;k < n;++k)
	for(int l = k+1;l < n;++l)
	{
		if(is_trang(P[i],P[j],P[k],P[l]) || is_trang(P[i],P[k],P[j],P[l]))
		{
			R[tot].p[0] = P[i];
			R[tot].p[1] = P[j];
			R[tot].p[2] = P[k];
			R[tot].p[3] = P[l];
			tot++;
		}
	}
	return tot;
}
double Max(double a,double b)
{
	return a > b? a:b;
}
int is_xj(point a1,point a2,point b1,point b2)
{
	if(dot(b1-a1,a2-a1)*dot(b2-a1,a2-a1) < 0 || fabs(dot(b1-a1,a2-a1)*dot(b2-a1,a2-a1)) < eps)
	if(dot(a1-b1,b2-b1)*dot(a2-b1,b2-b1) < 0 || fabs(dot(a1-b1,b2-b1)*dot(a2-b1,b2-b1)) < eps)
	{
		double m = dis(a1,b1);
		m = Max(m,dis(a1,b2));
		m = Max(m,dis(a1,a2));
		m = Max(m,dis(a2,b1));
		m = Max(m,dis(a2,b2));
		m = Max(m,dis(b1,b2));
		if(fabs(dot(a1-a2,b1-b2))<eps && m > dis(a1,a2)+dis(b1,b2)) return 0;
		return 1;
	}
	return 0;
}
struct node
{
	point p[2];
}rr1[4],rr2[4];
int judge(rect a,rect b)
{
	rr1[0].p[0] = a.p[0],rr1[0].p[1] = a.p[1];
	rr1[1].p[0] = a.p[0],rr1[1].p[1] = a.p[2];
	rr1[2].p[0] = a.p[2],rr1[2].p[1] = a.p[3];
	rr1[3].p[0] = a.p[1],rr1[3].p[1] = a.p[3];

	rr2[0].p[0] = b.p[0],rr2[0].p[1] = b.p[1];
	rr2[1].p[0] = b.p[0],rr2[1].p[1] = b.p[2];
	rr2[2].p[0] = b.p[1],rr2[2].p[1] = b.p[3];
	rr2[3].p[0] = b.p[2],rr2[3].p[1] = b.p[3];
	for(int i = 0;i < 4;++i)
	for(int j = 0;j < 4;++j)
	if(is_xj(rr1[i].p[0],rr1[i].p[1],rr2[j].p[0],rr2[j].p[1]))
	return 0;
/*	for(int i = 0;i < 4;++i)     //只要枚举一个矩形的顶点是不是在另一个矩形里面或者边上
	for(int j = i+1;j < 4;++j)
	{
		for(int k = 0;k < 4;++k)
		for(int l = k+1;l < 4;++l)
		{
			if(is_xj(a.p[i],a.p[j],b.p[k],b.p[l]))
			return 0;
		}
	}*/
	return 1;
}

bool cmp(point a,point b)
{
	if(fabs(a.x-b.x) > eps)
	return a.x < b.x;
	else return a.y < b.y;
}
double get_area(rect a)
{
	return dis(a.p[0],a.p[1]) * dis(a.p[0],a.p[2]);
}
int judge_in(rect a,rect b)
{
    int flag = 0;
    for(int i = 0;i < 4;++i)
    {
        if((a.p[i].x > b.p[0].x && a.p[i].x < b.p[2].x)) flag++;
        if((a.p[i].y > b.p[0].y && a.p[i].y < b.p[1].y)) flag++;
    }
    return flag >= 8;
}

int main()
{
	//printf("%d\n",is_trang(point(0,0),point(1,0),point(1,1),point(0,1)));
//	freopen("in","r",stdin);
	int n;
	while(scanf("%d",&n),n)
	{
		for(int i = 0;i < n;++i)
		scanf("%lf%lf",&P[i].x,&P[i].y);
		sort(P,P+n,cmp);
		int tot = make(n);   //构造tot个矩形
		double Max_ans = 0;
		for(int i = 0;i < tot;++i)
		sort(R[i].p,R[i].p+4,cmp);
//		printf("tot =  %d\n",tot);
		for(int i = 0;i < tot;++i)
		{
    //        for(int j = 0;j < 4;++j)
	//		printf("%.0lf %.0lf ",R[i].p[j].x,R[i].p[j].y);
	//		puts("");
		}
	//	printf("dlfjksdklj = %d\n",judge_in(R[1],R[0]));
		for(int i = 0;i < tot;++i)
		for(int j = i;j < tot;++j)
		if(judge(R[i],R [j]))    //满足位置关系 ,注意一个矩形包含另一个矩形的情况
		{
			double t = get_area(R[i]) + get_area(R[j]);    //求两个矩形的面积
			if(judge_in(R[i],R[j]) || judge_in(R[j],R[i])) Max_ans = Max(Max_ans,Max(get_area(R[i]),get_area(R[j])));
			else Max_ans = Max(Max_ans,t);
		}
		if(tot <= 0 || fabs(Max_ans) < eps) printf("imp\n");
		else printf("%.0lf\n",Max_ans+eps);
	}
	return 0;
}
