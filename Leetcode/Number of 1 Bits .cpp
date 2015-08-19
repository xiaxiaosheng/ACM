class Solution {
public:
    int hammingWeight(uint32_t n) {
        int tot = 0;
        while(n)
        {
            tot += (n & 1);
            n >>= 1;
        }
        return tot;
    }
};
