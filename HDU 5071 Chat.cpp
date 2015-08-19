#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<deque>
using namespace std;

deque<int> que;
deque<int>::iterator iter;
map<int,int> mp;

int T,n,x,top,istop;
void Add()
{
    scanf("%d",&x);
    if(mp[x] == 0)
    {
        que.push_back(x);
        mp[x] = -1;            //因为map查找没有时返回是0,为了避免冲突,初始化为-1
        puts("success.");
    }
    else puts("same priority.");
}

void Close()
{
    scanf("%d",&x);
    if(mp[x] )
    {
        if(mp[x]  > 0) printf("close %d with %d.\n",x,mp[x]);
        else printf("close %d with 0.\n",x);
        if(istop && top == x) istop = 0;       // 关掉always状态的就要把这个标记取消掉,不然会出错,但是注释掉也过了,说明没有关掉always状态的操作
       //但个人觉得还是加上比较好,因为这个操作可以关掉一切存在的 窗口,不加这个可以过就是测试数据的问题了
        for(iter = que.begin();iter != que.end();++iter)
        if(*iter == x)
        {
            que.erase(iter);
            break;
        }
        mp.erase(x);
    }
    else puts("invalid priority.");
}
void Chat()
{
    scanf("%d",&x);
    int t;
    if(que.empty())
    {
        puts("empty.");
        return ;
    }
    if(istop) t = top;  //如果存在always top
    else t = *que.begin();
    if(mp[t] == -1) mp[t] = x;
    else mp[t] += x;
    puts("success.");
}
void Rotate()
{
    scanf("%d",&x);
    if(x > que.size())
    {
        puts("out of range.");
        return ;
    }
    int t = x - 1;
    iter = que.begin();
    while(t--) iter++;
    t = *iter;
    que.erase(iter);
    que.push_front(t);
    puts("success.");
}
void Prior()
{
    if(que.empty())
    {
        puts("empty.");
        return ;
    }
    deque<int>::iterator M = que.begin();
    for(iter = que.begin();iter != que.end();++iter)
    if(*M < *iter) M = iter;
    int t = *M;
    que.erase(M);
    que.push_front(t);
    puts("success.");
}
void Choose()
{
    scanf("%d",&x);
    if(mp[x] == 0)
    {
        puts("invalid priority.");
        return ;
    }
    for(iter = que.begin();iter != que.end();++iter)
    if(*iter == x)
    break;
    que.push_front(x);
    que.erase(iter);
    puts("success.");
}
void Top()
{
    scanf("%d",&x);
    if(mp[x] == 0)
    {
        puts("invalid priority.");
        return ;
    }
    istop = 1;
    top = x;
    puts("success.");
}
void Untop()
{
    if(istop == 0)
    {
        puts("no such person.");
        return ;
    }
    istop = 0;
    puts("success.");
}

int main()
{
//    freopen("in","r",stdin);
    char oper[10];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        mp.clear();
        que.clear();
        istop  = 0;   //是否存在top
        int kase = 1;
        while(n--)
        {
            scanf("%s",oper);
            printf("Operation #%d: ",kase++);
            if(!strcmp(oper,"Add")) Add();
            else if(!strcmp(oper,"Close")) Close();
            else if(!strcmp(oper,"Chat")) Chat();
            else if(!strcmp(oper,"Rotate")) Rotate();
            else if(!strcmp(oper,"Prior")) Prior();
            else if(!strcmp(oper,"Choose")) Choose();
            else if(!strcmp(oper,"Top")) Top();
            else if(!strcmp(oper,"Untop")) Untop();
        }
        if(istop != 0 && mp[top] > 0)
        {
            printf("Bye %d: %d\n",top,mp[top]);
            mp.erase(top);
            for(iter = que.begin();iter != que.end();++iter)
            if(*iter == top) break;
            que.erase(iter);
        }
        while(!que.empty())
        {
            if(mp[*que.begin()] > 0)
            printf("Bye %d: %d\n",*que.begin(),mp[*que.begin()]);
            mp.erase(*que.begin());
            que.pop_front();
        }
    }
    return 0;
}
