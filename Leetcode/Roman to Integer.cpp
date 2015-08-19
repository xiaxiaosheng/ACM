class Solution {
public:
    map<char,int> w;
    int romanToInt(string s) {
        w.clear();
        w['I'] = 1;
        w['V'] = 5;
        w['X'] = 10;
        w['L'] = 50;
        w['C'] = 100;
        w['D'] = 500;
        w['M'] = 1000;
        int ans = 0;
        for(int i = 0;i < s.length();++i)
        {
            if(i+1 < s.length() && w[s[i+1]] > w[s[i]])
            {
                ans += (w[s[i+1]] - w[s[i]]);
                i++;
            }
            else ans += w[s[i]];
        }
        return ans;
    }
};
