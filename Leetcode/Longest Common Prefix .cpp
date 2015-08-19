class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pre;
        if(strs.size() == 1)
            return strs[0];
        int f = 0,flag = 1;
        while(flag)
        {
            int t = 1,t2 = 0;
            for(int i = 1;i < strs.size();++i)
            {
                t2 = 1;
                if(strs[i].length() > f && strs[i-1].length() > f && strs[i][f] == strs[i-1][f])
                    ;
                else
                {
                    flag = t = 0;
                    break;
                }
            }
            if(!t2) break;
            if(strs.size() > 0 && strs[0].length() > f && t) pre += strs[0][f++];
        }
        return pre;
    }
};
