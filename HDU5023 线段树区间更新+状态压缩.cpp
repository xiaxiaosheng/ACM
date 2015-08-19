#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef __int64 LL;
typedef unsigned int UINT;
const int maxn = 1e6 + 5;

#define LEFT(a,b) ((a) << (b))
#define RIGHT(a,b) ((a) >> (b))

struct node
{
    UINT c,num;
    int l,r;
    node() {}
    node(const int t_l,const int t_r,const UINT t_c,const UINT t_num)
    {
        l = t_l,r = t_r;
        c = (1 << (t_c - 1));
        num = t_num;
    }
}tree[4*maxn];

void Init(const int p)
{
    if(tree[p].l == tree[p].r) return ;
    int mid = RIGHT(tree[p].l + tree[p].r,1);
    tree[LEFT(p,1)] = node(tree[p].l,mid,2,1);
    tree[LEFT(p,1)+1] = node(mid+1,tree[p].r,2,1);
    Init(LEFT(p,1));
    Init(LEFT(p,1)+1);
}
void paste(const int p,const int t_l,const int t_r,const UINT t_c)
{
    if(t_l > t_r) return ;
    if(t_l == tree[p].l && t_r == tree[p].r)
    {
        tree[p].c = t_c;
        tree[p].num = 1;
         return ;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    /*
    如果该段区间只有一种颜色，则要先把该段区间里的目标区间意外的区间涂成原来的颜色
    */
    if(1 == tree[p].num)
    {
        paste(LEFT(p,1),tree[p].l,mid,tree[p].c);
        paste(LEFT(p,1)+1,mid+1,tree[p].r,tree[p].c);
        /*
        if(t_r <= mid) paste(LEFT(p,1)+1,mid+1,tree[p].r,tree[p].c);
        else if(t_l <= mid && t_r > mid)
        {
            paste(LEFT(p,1),tree[p].l,t_l-1,tree[p].c);
            paste(LEFT(p,1)+1,t_r+1,tree[p].r,tree[p].c);
        }
        else if(t_l > mid) paste(LEFT(p,1),tree[p].l,mid,tree[p].c);
        */
    }
    if(t_r <= mid) paste(LEFT(p,1),t_l,t_r,t_c);
    else if(t_l <= mid && t_r > mid)
    {
        paste(LEFT(p,1),t_l,mid,t_c);
        paste(LEFT(p,1)+1,mid+1,t_r,t_c);
    }
    else if(t_l > mid) paste(LEFT(p,1)+1,t_l,t_r,t_c);
    
    tree[p].c = tree[LEFT(p,1)].c | tree[LEFT(p,1)+1].c;
    tree[p].num = 0;
    for(int i = 0;i <= 29;i++)
        if(tree[p].c & (1 << i))
            tree[p].num++;
}

void quire(const int p,const int t_l,const int t_r,UINT& t_c)
{
    if(1 == tree[p].num || (tree[p].l == t_l && tree[p].r == t_r))
    {
        t_c |= tree[p].c;
        return ;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    if(t_r <= mid) quire(LEFT(p,1),t_l,t_r,t_c);
    else if(t_l <= mid && t_r > mid)
    {
        quire(LEFT(p,1),t_l,mid,t_c);
        quire(LEFT(p,1)+1,mid+1,t_r,t_c);
    }
    else if(t_l > mid) quire(LEFT(p,1)+1,t_l,t_r,t_c);
}
void print()
{
    for(int i = 1;i <= 9;++i)
        printf("%d ",tree[i].c);
    puts("");
    for(int i = 1;i <= 9;i++)
        printf("%d ",tree[i].num);
    puts("");
}
int main()
{
//    freopen("in.txt","r",stdin);
    int n,m;
    while(scanf("%d%d",&n,&m),m+n)
    {
        tree[1] = node(1,n,2,1);
        Init(1);
        char oper[3];
        while(m--)
        {
            scanf("%s",oper);
            if('P' == oper[0])
            {
                int x,y,c;
                scanf("%d%d%d",&x,&y,&c);
                paste(1,x,y,1 << (c - 1));
            //    print();
            }
            else
            {
                int x,y;
                UINT t_c = 0;
                scanf("%d%d",&x,&y);
                quire(1,x,y,t_c);
                bool flag = false;
                for(int i = 0;i <= 29;++i)
                    if(t_c & (1 << i))
                    {
                        if(flag) printf(" ");
                        flag = true;
                        printf("%d",i+1);
                    }
                if(flag) puts("");
            //    print();
            }
        }
    }
    return 0;
}
