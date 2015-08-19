#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long INT;

INT a,b,s;
INT Abs(INT d)
{
	return d > 0? d:(-1)*d;
}
int main()
{
	while(scanf("%lld%lld%lld",&a,&b,&s)!=EOF)
	{
		a = Abs(a);
		b = Abs(b);
		if((a+b) <= s && (s - a - b) % 2 == 0)
		puts("Yes");
		else puts("No");
	}
	return 0;
}
	
