class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() <= 0) return false;
        map<int,bool> mp;
        mp.clear();
        for(int i = 0;i < nums.size();++i)
        {
            if(mp[nums[i]] == true) return true;
            mp[nums[i]] = true;
        }
        return false;
    }
};
