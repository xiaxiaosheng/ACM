#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
const int maxn = 50050;
const double eps = 1e-14;

int T,n,k;
double pos[maxn],sump[maxn],sump2[maxn];
int main()
{
  //  freopen("in","r",stdin);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        for(int i = 1;i <= n;++i)
        scanf("%lf",&pos[i]);
        sort(pos+1,pos+n+1);
        sump[0] = sump[1] = sump2[0] = sump2[1] = 0;
        for(int i = 1;i <= n;++i)
        {
            sump[i] = sump[i-1] + pos[i];
            sump2[i] = sump2[i-1] + pos[i] * pos[i];
        }
        int m = n - k;
        if(m  <= 1)
        {
            puts("0");
            continue;
        }
        double ans = sump2[m] + m * (sump[m] / m) * (sump[m] / m) - 2.0 * (sump[m] / m) * sump[m];
        for(int e = m;e <= n;++e)
        {
            int s = e - m + 1;
            double eve = (sump[e] - sump[s-1]) / m;
            double temp = sump2[e] - sump2[s-1] + m * eve * eve - 2.0 * eve * (sump[e] - sump[s-1]);
            ans = min(ans,temp);
        }
        printf("%.12lf\n",ans);
    }
    return 0;
}
