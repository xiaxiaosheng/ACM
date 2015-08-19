#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 510;
struct point	
{
    int x,y,v;
    int flag;
	point(int m = 0,int n = 0):x(m),y(n) {}
	friend point operator - (point a,point b)
	{
		return point(a.x-b.x,a.y-b.y);
	}
}p[maxn],ans[maxn],temp[maxn],t[maxn];
int n,que[maxn];
bool cmp(point a,point b)
{
	if(a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}
int dot(point p1,point p2)
{
    return p1.x*p2.y - p2.x*p1.y;
}
int graph(point* p,int n)
{
    sort(p,p+n,cmp);
    ans[0] = p[0];
    ans[1] = p[1];
    int top = 1,len;
    for(int i = 2;i < n;++i)
    {
        while(top && dot(p[i]-ans[top-1],ans[top]-ans[top-1]) > 0) top--;
        ans[++top] = p[i];
    }
    len = top;
    for(int i = n-1;i >= 0;--i)
    {
        while(top != len && dot(p[i]-ans[top-1],ans[top]-ans[top-1]) > 0) top--;
        ans[++top] = p[i];
    }
    return top;
}
int main()
{
	int kase = 1;
	while(scanf("%d",&n)&&n)
	{
		int maxv = -1;
		for(int i = 0;i < n;++i)
		{
			scanf("%d%d%d",&temp[i].x,&temp[i].y,&temp[i].v);
			maxv = max(maxv,temp[i].v);
			temp[i].flag = i;
		}
		if(maxv == 0)   //当速度全为0的时候，则所有的管辖的地方的面积都不是无限的 
		{
			printf("Case #%d: ",kase++);
			for(int i = 0;i < n;++i)
			printf("0");
			puts("");
			continue;
		}
		sort(temp,temp+n,cmp);
		for(int i = 0;i < n;++i)
			for(int j = i + 1;j < n;++j)
				if(temp[i].x==temp[j].x && temp[i].y == temp[j].y && temp[i].v == temp[j].v)
					temp[i].flag = temp[j].flag = n + 2;  //把在同一个位置且速度相同的点的位置标记成n+2就不会对结果产生影响了 
		int f = 0,m;
		for(int i = 0;i < n;++i)   //筛选出速度最大的点 
			if(temp[i].v == maxv)
			{
		//		if(!(temp[i].x == temp[i+1].x&&temp[i].y==temp[i+1].y))
				p[f++] = temp[i];
			}
		int tt = f;
		f = 0;
		for(int i = 0;i < tt-1;++i)    //去除位置相同的点 
			if(!(p[i].x == p[i+1].x&&p[i].y==p[i+1].y))
				t[f++] = p[i];
		t[f++] = p[tt-1];
		if(f <= 3)
		{
			for(int i = 0;i < f;++i)
				ans[i] = t[i];
			m = f;
		}
		else
		{
	//		printf("m = %d\n",f);
	//		for(int i = 0;i < f;++i)
	//			printf("%.0lf %.0lf\n",p[i].x,p[i].y);
			m = graph(t,f);
		}
		
		//printf("m = %d\n",m);
		//for(int i = 0;i < m;++i)
		//	printf("%.0lf %.0lf\n",ans[i].x,ans[i].y);
		memset(que,0,sizeof(que));
		for(int i = 0;i < m;++i)
			que[ans[i].flag] = 1;
		printf("Case #%d: ",kase++);
		for(int i = 0;i < n;++i)
			printf("%d",que[i]);
		puts("");
	}
}
/*
8
1 3 1
0 0 1
-1 1 1
-2 2 1
1 3 1
0 4 1
-4 4 1
-4 1 1
7
0 4 1
-4 4 1
-4 1 1
0 0 1
-1 1 1
-2 2 1
1 3 1
*/
