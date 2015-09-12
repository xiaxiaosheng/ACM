/*
HDU 1210
Link:http://acm.hdu.edu.cn/showproblem.php?pid=1210
2n������λ�ñ��Ϊ��1��2n
Ҫʹ���лص���ʼ�����У�Ҳ���ǵ�1�ص����1��λ�ã����оͻ�ԭ��
���ԣ�ֻҪ�ж�1Ҫ�������ٴ�ϴ�ƲŻ�ص����1��λ��
xΪ��ǰ����λ�õı�ţ�f(x)Ϊ��һ��1��λ��
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
