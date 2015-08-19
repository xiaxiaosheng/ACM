 #include<cstdio>
 #include<cstring>
 #include<iostream>
 #include<algorithm>
 using namespace std;
 const int maxn = 200005;
 struct node
 {
    int M,l,r;
}tree[4*maxn];
 int A[maxn];
int n,m,ans;
int Max(int a,int b)
{
    return a > b? a : b;
}
 void Init_tree(int p)
 {
    if(tree[p].l == tree[p].r)
    {
        tree[p].M = A[tree[p].l];
        return ;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    tree[2*p].l = tree[p].l;
    tree[2*p].r = mid;
    tree[2*p+1].l = mid + 1;
    tree[2*p+1].r = tree[p].r;
    tree[2*p].M = tree[2*p+1].M = 0;
    Init_tree(2*p);
    Init_tree(2*p+1);
    tree[p].M = Max(tree[2*p].M,tree[2*p+1].M);
}
void update(int p,int l,int s)
{
    if(tree[p].l == l && tree[p].r == l)
    {
        tree[p].M = s;
        return ;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    if(l <= mid) update(2*p,l,s);
    else update(2*p+1,l,s);
    tree[p].M = Max(tree[2*p].M,tree[2*p+1].M);
}
void query(int p,int l,int r)
{
    if(tree[p].l == l && tree[p].r == r)
    {
        ans = Max(ans,tree[p].M);
        return ;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    if(r <= mid) query(2*p,l,r);
    else if(l <= mid && r > mid)
    {
        query(2*p,l,mid);
        query(2*p+1,mid+1,r);
    }
    else if(l > mid) query(2*p+1,l,r);
}

 int main()
 {
//    freopen("in","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i = 1;i <= n;++i)
        scanf("%d",&A[i]);
        tree[1].l = 1,tree[1].r = n;
        Init_tree(1);
        char oper[5];
        int a,b;
        while(m--)
        {
            scanf("%s %d %d",oper,&a,&b);
            if(oper[0] == 'U') update(1,a,b);
            else
            {
                ans = 0;
                query(1,a,b);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
