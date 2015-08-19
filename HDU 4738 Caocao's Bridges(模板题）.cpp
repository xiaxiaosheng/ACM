#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1005;
const int maxm = 1000005;

struct Edge
{
    int to,next,w;
    bool cut;
}edge[maxm];

int head[maxn],tot,pre[maxn];
int find(int n)
{
    return pre[n] == n? n : pre[n] = find(pre[n]);
}
int Low[maxn],DFN[maxn],Stack[maxn];
int Index,top;
bool Instack[maxn];
bool cut[maxn];
int add_block[maxn];
int bridge;
void addedge(int u,int v,int w)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    edge[tot].w = w;
    edge[tot].cut = false;
    head[u] = tot++;
}
void Tarjan(int u,int pre)
{
    int v;
    Low[u] = DFN[u] = ++Index;
    Stack[top++] = u;
    Instack[u] = true;
    int son = 0;
    int pre_cnt = 0;
    for(int i = head[u];i != -1;i = edge[i].next)
    {
        v = edge[i].to;
        if(v == pre && pre_cnt == 0)
        {
            pre_cnt ++;
            continue;
        }
        if(!DFN[v])
        {
            son++;
            Tarjan(v,u);
            if(Low[u] > Low[v]) Low[u] = Low[v];
            if(Low[v] > DFN[u])
            {
                bridge++;
                edge[i].cut = true;
                edge[i^1].cut = true;
            }
            if(u != pre && Low[v] >= DFN[u])
            {
                cut[u] = true;
                add_block[u]++;
            }
        }
        else if(Low[u] > DFN[v])
        Low[u] = DFN[v];
    }
    if(u == pre && son > 1) cut[u] = true;
    if(u == pre) add_block[u] = son - 1;
    Instack[u] = false;
    top--;
}
int is_liantong(int n)
{
    int s = find(1);
    for(int i = 2;i <= n;++i)
    if(s != find(i))
    return 0;
    return 1;
}

int main()
{
  //      freopen("in","r",stdin);
        int n,m;
        while(scanf("%d%d",&n,&m),n&&m)
        {
            tot = 0;
            memset(head,-1,sizeof(head));
            memset(DFN,0,sizeof(DFN));
            memset(Instack,false,sizeof(Instack));
            memset(add_block,0,sizeof(add_block));
            memset(cut,0,sizeof(cut));
            Index = top = 0;
            bridge = 0;
            int u,v,w;
            for(int i = 1;i <= n;++i)
            pre[i] = i;
            for(int i = 0;i < m;++i)
            {
                scanf("%d%d%d",&u,&v,&w);
                addedge(u,v,w);
                addedge(v,u,w);
                pre[find(u)] = find(v);
            }
            if(!is_liantong(n))
            {
                printf("0\n");
                continue;
            }
            for(int i = 1;i <= n;++i)
            if(!DFN[i])
            Tarjan(i,i);
            int ans = 0x7fffffff;
            for(int i = 0;i < tot;++i)
            {
                if(edge[i].cut == true)
                {
                    ans = min(ans,edge[i].w);
                }
            }
            ans = max(ans,1);
            printf(ans > 10000? "-1\n":"%d\n",ans);
        }
        return 0;
}
