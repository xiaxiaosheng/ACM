class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() <= 0)
            return 0;
        int dp[100005];
        memset(dp,0,sizeof(dp));
        dp[1] = nums[0];
        for(int i = 1;i < nums.size();i++)
        {
            dp[i+1] = max(dp[i],dp[i-1] + nums[i]);
        }
        return dp[nums.size()];
    }
};
