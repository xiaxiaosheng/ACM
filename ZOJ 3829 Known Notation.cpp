#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include<deque>
using namespace std;
#define maxn 1005
int T;
char str[maxn];
deque<int> que;
void Swap(int d,char* s)
{
    str[d] = '1';
    int len = strlen(s);
    for(int i = len-1;i >= 0;--i)
    if(s[i] != '*')
    {
        s[i] = '*';
        break;
    }
}

int main()
{
//    freopen("in","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",str);
        int len  = strlen(str);
        que.clear();
        int ans = 0,t1 = 0,t2 = 0;
        for(int i = 0;i < len;++i)   //扫出数字跟*的个数
        {
            if(str[i] == '*') t1++;
            else t2++;
        }
        if(t2 < t1 +1)
        {
            ans += (t1+1 - t2);
            for(int i = 0;i < ans;++i)
            que.push_back(1);    //全部插入到最前面
        }
        int x = 0;
       for(int i = 0;x < 20 && i < len;++i)
       {
            if(str[i] != '*') que.push_back(1);
            else
            {
                if(que.size() < 2)
                {
                    Swap(i,str);     //交换操作
                    ans++;
                    i--;
                }
                else
                {
                    que.pop_back();
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
