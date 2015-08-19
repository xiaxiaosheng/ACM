class Solution {
public:
    void rotate(int nums[], int n, int k) {
        vector<int> t;
        t.clear();
        for(int i = 0;i < n;++i)
            t.push_back(nums[i]);
        for(int i = 0;i < n;++i)
        {
            nums[k=k%n] = t[i];
            k++;
        }
    }
};
