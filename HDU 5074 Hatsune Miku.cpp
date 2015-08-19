#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

int T,n,m;
int value[55][55],note[105],dp[105][55];
int main()
{
   // freopen("in","r",stdin);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= m;++i)
        for(int j  =1;j <= m;++j)
        scanf("%d",&value[i][j]);
        for(int i = 1;i  <= n;++i)
        scanf("%d",&note[i]);
        memset(dp,0,sizeof(dp));
        for(int i = 2;i <= n;++i)
        {
            if(note[i] == -1)
            {
                for(int j = 1;j <= m;++j)
                {
                    if(note[i-1] == -1)
                    for(int k = 1;k <= m;++k)
                    dp[i][j] = max(dp[i][j],dp[i-1][k] + value[k][j]);
                    else dp[i][j] = max(dp[i][j],dp[i-1][note[i-1]] + value[note[i-1]][j]);
                }
            }
            else
            {
                if(note[i-1] == -1)
                for(int k = 1;k <= m;++k)
                dp[i][note[i]] = max(dp[i][note[i]],dp[i-1][k] + value[k][note[i]]);
                else dp[i][note[i]] = max(dp[i][note[i]],dp[i-1][note[i-1]] + value[note[i-1]][note[i]]);
            }
        }
        int ans = 0;
        for(int i = 1;i <= m;++i)
        ans = max(ans,dp[n][i]);
        printf("%d\n",ans);
    }
    return 0;
}
