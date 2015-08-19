#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;
const LL MOD = 1e9+7;
LL Power(LL x,LL y)
{
	if(y == 1) return x;
	if(y % 2 == 0)
	{
		return Power(x*x%MOD,y / 2);
	}
	else
	{
		LL temp = Power(x*x%MOD,y/2) % MOD;
		return (temp * x) % MOD;
	}
}
int main()
{
	LL x,y;
	while(scanf("%lld%lld",&x,&y)!=EOF)
	{
		LL sum = 0;
		for(LL i = 1;i <= x;++i)
		{
			sum += Power(i,y);
			sum %= MOD;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
	
