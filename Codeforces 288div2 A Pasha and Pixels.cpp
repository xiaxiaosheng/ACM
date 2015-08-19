#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int mat[1005][1005];

int n,m,k,x,y;
int judge(int x,int y)
{
    if(mat[x-1][y-1]&&mat[x-1][y]&&mat[x][y-1]&&mat[x][y])
    return 1;
    if(mat[x-1][y]&&mat[x][y]&&mat[x-1][y+1]&&mat[x][y+1])
    return 1;
    if(mat[x][y-1]&&mat[x][y]&&mat[x+1][y-1]&&mat[x+1][y])
    return 1;
    if(mat[x][y]&&mat[x+1][y]&&mat[x][y+1]&&mat[x+1][y+1])
    return 1;
    return 0;
}
int main()
{
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        memset(mat,0,sizeof(mat));
        int flag = 0;
        for(int i = 1;i <= k;++i)
        {
            scanf("%d%d",&x,&y);
            mat[x][y] = 1;
            if(flag == 0 && judge(x,y))
            {
                flag = i;
            }
        }
        printf("%d\n",flag);
    }
    return 0;
}   
