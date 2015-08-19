#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 200100;
char str[maxn];
int Up[30],Low[30];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%s",str);
		memset(Up,0,sizeof(Up));
		memset(Low,0,sizeof(Low));
		int ans = 0,len = strlen(str);
		for(int i = 0;i < len;i += 2)
		{
			Low[str[i]-'a']++;
			if(Low[str[i+1]-'A'] == 0)
			{
				ans++;
			}
			else Low[str[i+1]-'A']--;
		}
		printf("%d\n",ans);
	}
	return 0;
}	
