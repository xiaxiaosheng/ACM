#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int m,tt,r,T[305],t[1010],local[1010];
void light(int d)
{
	int lf = r - t[d],l = d-1;
	while(lf--)
	{
		for(;l >= 0;--l)
			if(local[l] == 0)
			{
				local[l] = 1;
				for(int j = l+1;j <= l+tt;++j)
					t[j]++;
				break;
			}
	}
}



int main()
{
	while(scanf("%d%d%d",&m,&tt,&r)!=EOF)
	{
		memset(t,0,sizeof(t));    //表示该时间点当前有几根蜡烛在燃烧
		memset(local,0,sizeof(local));  //表示该时间点正在点蜡烛
		int d,flag = 1;
		for(int i = 0;i < m;++i)
		{
			scanf("%d",&d);
			d += 400;
			if(t[d] < r)
			light(d);
			if(t[d] < r)
			{
				flag = 0;
			//	break;
			}
		}
		if(!flag)
		{
			printf("-1\n");
			continue;
		}
		int tot = 0;
		for(int i = 0;i < 1000;++i)
			tot += local[i];
		printf("%d\n",tot);
	}
	return 0;
}
