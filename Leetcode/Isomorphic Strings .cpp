class Solution {
public:
    bool judge(string s,string t){
        int flag[200];
        memset(flag,0,sizeof(flag));
        for(int i = 0;i < s.length();i++)
        {
            if(flag[s[i]] == 0)
                flag[s[i]] = t[i];
            else if(flag[s[i]] != t[i])
                return false;
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
         return judge(s,t) && judge(t,s);
    }
};
