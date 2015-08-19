#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int A[100005],visit[100005];
int main()
{
	int n,p;
	while(scanf("%d%d",&n,&p)!=EOF)
	{
		char str[105];
		for(int i = 1;i <= n;++i)
		scanf("%d%s",&A[i],str);
		int i = 1,j = n,flag = 0,f = n;
		memset(visit,0,sizeof(visit));
		while(n > 1)
		{
			n--;
			if(flag == 0)
			{
				visit[j] = 1;
				j--;
				flag = 1;
			}
			else if(flag == 1)
			{
				visit[i] = 1;
				i++;
				flag = 2;
			}
			else if(flag == 2)
			{
				if((p-i) == (j-p))
				flag = 0;
				else
				{
					if((p-i) > (j-p))
					{
						visit[i] = 1;
						i++;
					}	
					else
					{
						visit[j] = 1;
						j--;
					}
					flag = 0;
				}
			}
		}
		printf(visit[p]? "NO\n":"YES\n");
	}
	return 0;
}		
