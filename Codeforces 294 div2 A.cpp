#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
char mp[10][10];
int w[100];
int main()
{
	w['q'-'a'] = 9;
	w['r'-'a'] = 5;
	w['b'-'a'] = 3;
	w['n'-'a'] = 3;
	w['p'-'a'] = 1;
	w['k'-'a'] = 0;
	for(int i = 0;i < 8;++i)
	scanf("%s",mp[i]);
	int a = 0,b = 0;
	for(int i = 0;i < 8;++i)
	for(int j = 0;j < 8;++j)
	if(mp[i][j] >= 'A' && mp[i][j] <= 'Z')
	a += w[mp[i][j]-'A'];
	else if(mp[i][j] >= 'a' && mp[i][j] <= 'z')
	b += w[mp[i][j] - 'a'];
	if(a == b)
	printf("Draw\n");
	else printf(a > b? "White\n":"Black\n");
	return 0;
}
