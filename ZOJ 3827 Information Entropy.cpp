#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps = 1e-12;
int T,n;
char str[10];
double (*f)(double);
int main()
{
    freopen("in","r",stdin);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%s",&n,str);
        if(str[0] == 'b') f = log2;
        else if(str[0] == 'n') f = log;
        else if(str[0] == 'd') f = log10;
        double ans = 0,d;
        while(n--)
        {
            scanf("%lf",&d);
            ans -= (d / 100) * (*f)(d / 100);
        }
        printf("%.10lf\n",ans+eps);
    }
    return 0;
}


