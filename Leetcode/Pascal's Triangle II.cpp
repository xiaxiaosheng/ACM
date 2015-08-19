class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> t;
        t.clear();
        t.push_back(1);
        int pre = 1,th;
        for(int i = 1;i <= rowIndex;++i)
        {
            pre = 1;
            for(int j = 1;j < i;++j)
            {
                th = pre;
                pre = t[j];
                t[j] = th + t[j];
            }
            t.push_back(1);
        }
        return t;
    }
};
