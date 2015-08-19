#include <cstdio>
#include <cstring>
#include<iostream>
#include <algorithm>

using namespace std;
#define LL __int64//待会记得改
#define maxn 100010
struct node
{
	LL tot,p;
	LL s1,s2;
	int next;
}all[maxn];
int find_s1(LL d,node* temp,int l,int r)
{
	while(l < r)
	{
		int mid = (l + r) / 2;
		if(d <= temp[mid].s1) r = mid;
		else if(d > temp[mid].s1) l = mid + 1;
	}
	if(!(d >= temp[l].s1 && d < temp[l].s2)) return l-1;
	return l;
}
LL Min(LL a,LL b)
{
	return a <= b? a:b;
}
LL Max(LL a,LL b)
{
	return a >= b? a:b;
}
int main()
{
//	freopen("in","r",stdin);
	int T,n,m;
    scanf("%d",&T);
	LL d,s = 0,t1,t2;
	while(T--)
	{
		scanf("%d%d",&n,&m);
		scanf("%I64d",&s);
		for(int i = 0;i < n-1;++i)
		{
			scanf("%I64d%I64d",&all[i].p,&all[i].s2);
			all[i].s1 = s;
			all[i].tot = all[i].s1 * all[i].p;
			s = all[i].s2;
		}
		all[n-1].s1 = s;
		all[n-1].s2 = 0x7fffffff;
		scanf("%I64d",&all[n-1].p);
		all[n-1].tot = all[n-1].p * all[n-1].s1;
		all[n-1].next = n;
		all[n] = all[n-1];
		int pp = n;
		for(int i = n-1;i >= 0;--i)
		{
            all[i].next = pp;
            if(all[pp].tot > all[i].tot) pp = i;
        }
		for(int i = 0;i < m;++i)
		{
			scanf("%I64d",&d);
			int q = find_s1(d,all,0,n-1);
			t1 = all[q].p * d;
			if(all[q].f != n-1)    //前n-1个
			{
				t2 = all[all[q].next].p * Max(all[all[q].next].s1,d);
				printf("%I64d\n",Min(t1,t2));
			}
			else printf("%I64d\n",t1);    //第n个的情况
		}
	}
	return 0;
}
