class Solution {
public:
    int titleToNumber(string s) {
        int d  = 0,c = 1;
        for(int i = s.length() - 1;i >= 0;i--)
        {
            d += (s[i] - 'A'+1) * c;
            c *= 26;
        }
        return d;
    }
};
