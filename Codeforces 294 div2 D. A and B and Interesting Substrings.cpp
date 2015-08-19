#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long INT;
const int maxn = 100010;
struct node
{
	int c,l;
}T[26][maxn];
INT w[30],A[maxn];
char str[maxn];
map<INT,INT> mp;
int main()
{
	while(scanf("%lld",&w[0])!=EOF)
	{
		for(int i = 1;i < 26;++i)
		scanf("%lld",&w[i]);
		scanf("%s",str);
		memset(A,0,sizeof(A));
		int len = strlen(str);
		A[0] = w[str[0]-'a'];
		for(int i = 1;i < len;++i)
		A[i] = A[i-1] + w[str[i]-'a'];
		memset(T,0,sizeof(T));
		memset(T,0,sizeof(T));
		for(int i = 0;i < len;++i)
		{
			T[str[i]-'a'][0].l++;
			T[str[i]-'a'][T[str[i]-'a'][0].l].l = i;   //把所有的相同的字母的位置放在一起 
		}
		INT ans = 0;
		for(int i = 0;i < 26;++i)
		if(T[i][0].l > 1)
		{
			mp.clear();
			for(int j = 1;j <= T[i][0].l;++j)
			{
				if(T[i][j].l > 0)
				ans += mp[A[T[i][j].l-1]];  //统计这个位置的前一个位置的前缀和的值在前面出现的次数 
				mp[A[T[i][j].l]]++; 
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
