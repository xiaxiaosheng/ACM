#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;
typedef struct node
{
	int flag;
	node *next;
}Linklist;
int n,inter[610][2],temp[2000];
int reader(Linklist* head,int* temp)
{
	int flag = 0,t = 0,f = 0;
	Linklist *p = head->next;
	while(p != NULL)
	{
		if(flag == 0)
		{
			temp[f++] = t;
			t = 0;
		}
		t++;
		flag += p->flag;
		p = p->next;
	}
	if(flag == 0)
		temp[f++] = t;
	return f;
}
void insert(Linklist* head,int tot)
{
	int f = 0;
	Linklist *q = new Linklist;
	q->flag = 1;
	q->next = head->next;
	head->next = q;
	Linklist *p = head;
	while(tot--)
	p = p->next;
	Linklist *t = new Linklist;
	t->flag = -1;
	t->next = p->next;
	p->next = t;
}
void clean(Linklist *p)
{
	if(p->next == NULL)
	{
		delete p;
		return ;
	}
	clean(p->next);
}
void print(Linklist *head)
{
	Linklist *p = head->next;
	while(p!= NULL)
	{
		printf("%d ",p->flag);
		p = p->next;
	}
	puts("");
}
int  main()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(int i = 0;i < n;++i)
			scanf("%d%d",&inter[i][0],&inter[i][1]);
		int flag = 0,t = 0;
		Linklist *head = new Linklist;
		head->flag = 0;    //初始化头节点,头节点不存信息 
		head->next = NULL;
		int ans = 1;
		for(int i = n - 1;i >= 0;--i)
		{
			int num = reader(head,temp);   //返回的是temp中数值的个数
			int ff = 0,tot = 1;
			for(int j = 0;j < num;++j)
			{
				tot += temp[j];
				if(tot >= inter[i][0] && tot <= inter[i][1])
				{
					insert(head,tot);   //执行在0位置插入'('跟在tot位置插入')'
					ff = 1;    //已找到满足的条件,退出
					break;
				}
			}
			if(ff == 0)
			{
				ans = 0;
				break;
			}
		}
		if(ans)
		{
			Linklist *p = head->next;
			while(p)
			{
				printf(p->flag == 1? "(":")");
				p = p->next;
			}
			puts("");
		}
		else puts("IMPOSSIBLE");
		clean(head);  //回收内存
	}
	return 0;
}	
