#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
char str[100];

int judge(char* s)
{
	int len = strlen(s);
	int i = 0,j = len-1;
	while(i <= j)
	{
		if(s[i] != s[j]) return 0;
		i++,j--;
	}
	return 1;
}

int main()
{
	while(scanf("%s",str)!=EOF)
	{
		int flag = 0,len = strlen(str);
		char temp[20];
		for(int i = 0;!flag && i <= len;++i)
		for(int k = 0;!flag && k < 26;++k)
		{
			for(int j = 0;j < i;++j)
			temp[j] = str[j];
			temp[i] = k + 'a';
			for(int j = i+1;j <= len;++j)
			temp[j] = str[j-1];
			temp[len+1] = NULL;
			if(judge(temp))
			flag = 1;
		}
		if(flag) printf("%s\n",temp);
		else printf("NA\n");
	}
	return 0;
}			
