/*
HDU 1210
Link:http://acm.hdu.edu.cn/showproblem.php?pid=1210
2n个数，位置编号为从1到2n
要使序列回到初始的序列，也就是当1回到编号1的位置，序列就还原了
所以，只要判断1要经过多少次洗牌才会回到编号1的位置
x为当前所在位置的编号，f(x)为下一次1的位置
1~n         2 * x
n+1 ~ 2*n   2*x - 2*n - 1
*/
#include <cstdio>

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        int tot = 1, loc = 2;
        while(loc != 1)
        {
            if(loc <= n) loc <<= 1;
            else if(loc > n && loc <= (n << 1)) loc = ((loc - n) << 1) - 1;
            tot++;
        }
        printf("%d\n", tot);
    }
    return 0;
}
