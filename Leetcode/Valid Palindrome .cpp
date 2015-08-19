class Solution {
public:
    char getlower(char ch){
        if(ch >= 'A' && ch <= 'Z')
            return ch + 32;
        else if(ch >= 'a' && ch <= 'z')
            return ch;
        else if(ch >= '0' && ch <= '9')
            return ch;
        else return 0;
    }
    bool isPalindrome(string s) {
        int p = 0,q = s.length()-1;
        while(p <= q){
            char a = getlower(s[p]);
            char b = getlower(s[q]);
            if(0 == a) p++;
            else if(0 == b) q--;
            else if(a == b) p++,q--;
            else if(a != b) return false;
        }
        return true;
    }
};
