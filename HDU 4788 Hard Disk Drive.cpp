#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const double P = 1000.0 / 1024;
int temp[200];
void Init()
{
    temp['B'] = 0;
    temp['K'] = 1;
    temp['M'] = 2;
    temp['G'] = 3;
    temp['T'] = 4;
    temp['P'] = 5;
    temp['E'] = 6;
    temp['Z'] = 7;
    temp['Y'] = 8;
}
int main()
{
    Init();
    int T,n,kase = 1;
    char str[10];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d[%s",&n,str);
        int t = temp[str[0]];
        double ans = 1;
        while(t--)
        ans *= P;
        printf("Case #%d: %.2lf%%\n",kase++,(1.0-ans) * 100.0);
    }
}
