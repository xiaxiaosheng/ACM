class Solution {
public:
    bool prim[2000005];
    Solution()
    {
        int maxn = 2000005;
        int M = sqrt(maxn);
        memset(prim,0,sizeof(prim));
        prim[1] = 1;
        for(int i = 2;i <= M;i++)
        {
            if(prim[i])
                continue;
            for(int j = i * i;j < maxn;j += i)
                prim[j] = 1;
        }
    }
    int countPrimes(int n) {
        int i = 2,tot = 0;
        while(i < n)
        {
            if(!prim[i++])
                tot++;
        }
        return tot;
    }
};
