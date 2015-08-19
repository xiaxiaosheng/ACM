#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long INT;

int judge(INT curr,INT goal)
{
	if(goal == curr) return 1;
	while(goal > 0)
	{
		if(goal & 1) goal --;
		else
		{
			goal >>= 1;
			if(curr == goal) return 1;
		}
	}
	return 0;
}
INT get(INT h,INT curr)
{
	int t = 0;
	while(curr)
	{
		curr >>= 1;
		t++;
	}
	t = h - t + 1;
	return (((INT)1 << t) - 1);
}
int main()
{
	INT h,n;
	while(scanf("%lld%lld",&h,&n)!=EOF)
	{
		h++;
		INT goal = n + ((INT)1 << (h-1)) - 1;
		INT curr = 1,tot = 0;
		int cho = 0;
		for(int i = 1;i < h;++i)
		{
			curr = curr << 1;
			curr += cho;
			cho = !cho;
			if(judge(curr,goal))
			tot++;
			else
			{
				tot += get(h,curr);    //加上整棵子树 
				tot++;
				if(curr % 2 == 0)   //调整回到正确的子树上 
				{
					 curr ++;
					 cho = 0;
				}
				else
				{
					curr--;
					cho = 1;
				}
			}
		}
		printf("%lld\n",tot);
	}
	return 0;
}
