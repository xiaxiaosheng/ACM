#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const double eps = 1e-8;
const int maxn = 10010,maxr = 150;

int A[maxn];
double mat[maxr][maxr],dp[maxn][maxr];

double Max(double a,double b)
{
    return a > b? a:b;
}
int main()
{
   // freopen("in","r",stdin);
    int m;
    while(scanf("%d",&m)!=EOF)
    {
        int R = m * (m -1) * (m-2) / 6;
        for(int i = 0;i < R;++i)
        for(int j = 0;j < R;++j)
        scanf("%lf",&mat[i][j]);
        int n;
        scanf("%d",&n);
        for(int i = 1;i <= n;++i)
        scanf("%d",&A[i]);
        memset(dp,0,sizeof(dp));
        for(int i = 0;i < R;++i)
        dp[0][i] = 1;
        for(int i = 1;i <= n;++i)
        {
            double M = 0;
            for(int j = 0;j < R;++j)
            {
                dp[i][j] = dp[i-1][j] * mat[j][A[i]];
                M = Max(M,dp[i][j]);
            }
            dp[i][A[i]] = M;
        }
//		for(int i = 1;i <= n;++i)
//		for(int j = 0;j < R;++j)
	//	printf(j == R-1? "%lf\n":"%lf ",dp[i][j]);
        double ans = 0;
        for(int i = 0;i < R;++i)
        ans = Max(ans,dp[n][i]);
        printf("%lf\n",ans);
    }
    return 0;
}
