class Solution {
public:
    string getread(string last){
        string ans = "";
        last += '#';   //添加一个任意的不是数字的作为结束
        int num = 0;
        for(int i = 0;i < last.length()-1;++i){
            num++;
            if(last[i] != last[i+1]){
                char temp[10];
                sprintf(temp,"%d",num);
                ans += temp;
                ans += last[i];
                num = 0;
            }
        }
        return ans;
    }
    string countAndSay(int n) {
        string s = "1";
        for(int i = 0;i < n-1;++i)
            s = getread(s);
        return s;
    }
};
