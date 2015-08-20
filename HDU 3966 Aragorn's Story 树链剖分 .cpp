#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;
const int maxn = 5e4+5;
#ifdef WIN32
    #define LL __int64
#else
    #define LL long long
#endif


int A[maxn],totw;
struct node
{
    int fa,son,top,w,size,deep;
}tree[maxn];
vector<int> vt[maxn];
int tr[maxn];

void dfs_1(int p,int last,int de)
{
    tree[p].son = -1;
    tree[p].fa = last;
    tree[p].deep = de;
    tree[p].size = 1;
    int num = vt[p].size();
    for(int i = 0;i < num;++i)
        if(vt[p][i] != last)
        {
            dfs_1(vt[p][i],p,de+1);
            tree[p].size += tree[vt[p][i]].size;
            if(-1 == tree[p].son || tree[vt[p][i]].size > tree[tree[p].son].size)
                tree[p].son = vt[p][i];
        }
}
void dfs_2(int p,int top)
{
    tree[p].w = ++totw;
    tree[p].top = top;
    if(tree[p].son != -1)
        dfs_2(tree[p].son,top);
    else return ;
    int num = vt[p].size();
    for(int i = 0;i < num;++i)
    {
        if(vt[p][i] != tree[p].fa && vt[p][i] != tree[p].son)
            dfs_2(vt[p][i],vt[p][i]);
    }
}

void sol()
{
    totw = 0;
    memset(tr,0,sizeof(tr));
    memset(tree,0,sizeof(tree));
    dfs_1(1,0,1);
    dfs_2(1,1);
}
int lowbit(int x)
{
    return x & (-x);
}
int query(int p)
{
    p = tree[p].w;
    int tot = 0;
    while(p >= 1)
    {
        tot += tr[p];
        p -= lowbit(p);
    }
    return tot;
}
void add(int n,int p,int d)
{
    while(p <= n)
    {
        tr[p] += d;
        p += lowbit(p);
    }
}
void update_sec(int n,int u,int v,int d)
{
    if(tree[u].w > tree[v].w) swap(u,v);
    add(n,tree[u].w,d);
    add(n,tree[v].w+1,-d);
}
void update(int n,int u,int v,int d)
{
    /*
    u,v不断靠近根结点
    */
    while(tree[u].top != tree[v].top)
    {
        if(tree[tree[u].top].deep < tree[tree[v].top].deep) swap(u,v);
        update_sec(n,tree[u].top,u,d);
        u = tree[tree[u].top].fa;
    }
    update_sec(n,u,v,d);
}

int main()
{
//    freopen("in.txt","r",stdin);
    int n,m,p;
    while(scanf("%d%d%d",&n,&m,&p)!=EOF)
    {
        for(int i = 1;i <= n;++i)
            scanf("%d",&A[i]);
        for(int i = 1;i <= n;++i)
            vt[i].clear();
        int x,y;
        for(int i = 0;i < m;++i)
        {
            scanf("%d%d",&x,&y);
            vt[x].push_back(y);
            vt[y].push_back(x);
        }
        sol();
        char oper[5];
        while(p--)
        {
            scanf("%s",oper);
            int x,y,z;
            if('Q' == oper[0])
            {
                scanf("%d",&x);
                printf("%d\n",A[x] + query(x));
            }
            else if('I' == oper[0])
            {
                scanf("%d%d%d",&x,&y,&z);
                update(n,x,y,z);
            }
            else if('D' == oper[0])
            {
                scanf("%d%d%d",&x,&y,&z);
                update(n,x,y,-z);
            }
        }
    }
    return 0;
}