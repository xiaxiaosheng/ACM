#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps = 1e-9;
int judge(double d)
{
	return fabs(d - (int)d) < eps;
}
int main()
{
	int sx,sy;
	while(scanf("%d%d",&sx,&sy)!=EOF)
	{
		if(sx > sy)
		{
			printf("-1\n");
			continue;
		}
		int ans = 0;
		double X = 1,Y = 1,p = ((double)(sy + 1)+eps) / sx;
		while(1)
		{
			if((int)(X+eps) >= sx && (int)(Y+eps) >= sy) break;
			//getchar();
			double temp = Y / X;
			if(temp < p && (int)(sx * ((Y+1) / X)+eps) <= sy)
			{
				int tt;
				if(judge(X * p+eps)) tt = (int)(X * p+eps) - 1;
				else tt = (int)X * p;
				ans += (tt - (int)(Y+eps));
				Y += (double)(tt - (int)(Y+eps));
			}
			else
			{
				double t = Y / X;
				X += 1;
				Y += t;
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
