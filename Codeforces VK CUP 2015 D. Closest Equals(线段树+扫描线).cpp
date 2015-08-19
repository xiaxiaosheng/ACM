#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<list>
using namespace std;
const int maxn = 500100,INF = 500100;
map<int,int> mp;

int n,m,A[maxn];
struct node
{
    int d,l,r;
}tree[4*maxn];
struct Node
{
    int flag,ans;
    int l,r;
}Q[maxn];
bool cmp(Node a,Node b)
{
    return a.l > b.l;
}
void maketree(node *tree,int p)
{
    if(tree[p].l == tree[p].r)
    {
        tree[p].d = INF;
        return ;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    tree[2*p].l = tree[p].l;
    tree[2*p].r = mid;
    tree[2*p+1].l = mid + 1;
    tree[2*p+1].r = tree[p].r;
    tree[2*p].d = tree[2*p+1].d = INF;
    maketree(tree,2*p);
    maketree(tree,2*p+1);
}
void update(node *tree,int p,int loc,int d)
{
    if(tree[p].l == tree[p].r)
    {
        tree[p].d = min(tree[p].d,d);
        return ;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    if(loc <= mid)
        update(tree,2*p,loc,d);
    else update(tree,2*p+1,loc,d);
      tree[p].d  = min(tree[2*p].d,tree[2*p+1].d);
}
int data_sear;
void search(node *tree,int p,int l,int r)
{
    if(l <= tree[p].l && r >= tree[p].r )
    {
        data_sear = min(data_sear,tree[p].d);
        return ;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    if(r <= mid) search(tree,2*p,l,r);
    else if(l <= mid && r > mid)
    {
        search(tree,2*p,l,mid);
        search(tree,2*p+1,mid+1,r);
    }
    else if(l > mid) search(tree,2*p+1,l,r);
}

bool cmp2(Node a,Node b)
{
    return a.flag < b.flag;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i = 1;i <= n;++i)
            scanf("%d",&A[i]);
        for(int i = 0;i < m;++i)
        {
            scanf("%d%d",&Q[i].l,&Q[i].r);
            Q[i].flag = i;
            Q[i].ans = INF;
        }
        sort(Q,Q+m,cmp);     //按照左端点排好序,方便下面二分查找
        tree[1].l = 1;
        tree[1].r = n;
        tree[1].d = INF;
        maketree(tree,1);   //构建好线段树
        mp.clear();
        int f = 0;   //指向当前的查询
        for(int i = n;i >= 1;--i)
        {
            if(mp[A[i]] != 0)
            update(tree,1,mp[A[i]],mp[A[i]]-i);   //更新线段树
            mp[A[i]] = i;
            while(f < m && Q[f].l == i)
            {
                data_sear = INF;
                search(tree,1,Q[f].l,Q[f].r);   //查询这个区间内的最小值
                Q[f].ans = (data_sear <= n? data_sear:-1);
                f++;
            }
        }
        sort(Q,Q+m,cmp2);
        for(int i = 0;i < m;++i)
            printf("%d\n",Q[i].ans);
    }
    return 0;
}
