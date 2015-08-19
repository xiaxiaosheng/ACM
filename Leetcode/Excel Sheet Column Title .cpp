class Solution {
public:
    string convertToTitle(int n) {
        char A[27]; 
        A[0] = 'Z';
        for(int i = 1;i < 26;i++)
            A[i] = i + 'A' - 1;
        string ans = "";
        while(n)
        {
            ans  = A[n % 26] + ans;
            n = (n - 1) / 26;
        }
        return ans;
    }
};
