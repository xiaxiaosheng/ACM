#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 1005;
int n,xd,yd,xt,yt,dd,dt;
bool flag[maxn][maxn],flag2[maxn][maxn];
int xx[4] = {0,1,0,-1};
int yy[4] = {1,0,-1,0};

int main()
{
  //  freopen("in","r",stdin);
    while(scanf("%d",&n),n)
    {
        scanf("%d%d%d%d%d%d",&xd,&yd,&dd,&xt,&yt,&dt);
        xd += 1,yd += 1;
        xt += 1,yt += 1;
        memset(flag,0,sizeof(flag));
        memset(flag2,0,sizeof(flag));
        for(int i = 0;i <= n+1;++i)    //先把周围给标记掉
        {
            flag[0][i] = flag2[0][i] = 1;
            flag[i][0] = flag2[i][0] = 1;
            flag[n+1][i] = flag2[n+1][i]  = 1;
            flag[i][n+1] = flag2[i][n+1] = 1;
        }
        int go_d = 1,go_t = 1,ans = 0;
        int temp = 0;
        while(1)
        {
            if(xd == xt && yd == yt)
            {
                ans = 1;
                break;
            }
            flag[xd][yd] = 1;
            flag2[xt][yt] = 1;
            if(go_d  && !flag[xd+xx[dd]][yd+yy[dd]])
            {
                xd += xx[dd];
                yd += yy[dd];
            }
            else if(go_d)
            {
                dd = (dd + 1) % 4;
                if(!flag[xd+xx[dd]][yd+yy[dd]])
                {
                    xd += xx[dd];
                    yd += yy[dd];
                }
                else go_d = 0;
            }
            if(go_t && !flag2[xt+xx[dt]][yt+yy[dt]])
            {
                xt += xx[dt];
                yt += yy[dt];
            }
            else if(go_t)
            {
                dt = (dt + 3) % 4;   //向左转
                if(!flag2[xt+xx[dt]][yt+yy[dt]])
                {
                    xt += xx[dt];
                    yt += yy[dt];
                }
                else go_t = 0;
            }
            if(!(go_d || go_t)) break;
        }
        if(ans == 0) printf("-1\n");
        else printf("%d %d\n",xd-1,yd-1);
    }
    return 0;
}
