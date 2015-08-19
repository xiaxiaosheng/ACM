#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps = 1e-9;
double judge(char* s)
{
    if(!strcmp(s,"A")) return 4.0;
    if(!strcmp(s,"A-")) return 3.7;
    if(!strcmp(s,"B+")) return 3.3;
    if(!strcmp(s,"B")) return 3.0;
    if(!strcmp(s,"B-")) return 2.7;
    if(!strcmp(s,"C+")) return 2.3;
    if(!strcmp(s,"C")) return 2.0;
    if(!strcmp(s,"C-")) return 1.7;
    if(!strcmp(s,"D")) return 1.3;
    if(!strcmp(s,"D-")) return 1.0;
    if(!strcmp(s,"F") || !strcmp(s,"P") || !strcmp(s,"N")) return 0;
}
int main()
{
 //   freopen("in","r",stdin);
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        double a = 0,b = 0,d;
        char s[10];
        for(int i = 0;i < n;++i)
        {
            scanf("%lf %s",&d,s);
            a += (d * judge(s));
            if(s[0] != 'P' && s[0] != 'N') b += d;
        }
        double ans;
        if(fabs(b) < eps) ans = 0;
        else ans = a / b;
        printf("%.2lf\n",ans);
    }
    return 0;
}


