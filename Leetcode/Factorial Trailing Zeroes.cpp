class Solution {
public:
    int trailingZeroes(int n) {
        typedef long long LL;
        LL t = 5,tot = 0;
        for(int i = 1;i <= 13;i++)
        {
            if(n < t) break;
            tot += n / t;
            t *= 5;
        }
        return tot;
    }
};
