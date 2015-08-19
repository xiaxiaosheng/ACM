/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > ans;
    void travle(TreeNode* p,int deep)
    {
        if(p->left != NULL)
            travle(p->left,deep+1);
        if(ans.size() < deep)
        {
            for(int i = ans.size();i < deep;++i)   //现在最大的深度是多就要插入多少个vector
            {
                vector<int> vt;
                vt.clear();
                ans.push_back(vt);
            }
        }
        ans[deep-1].push_back(p->val);
        if(p->right != NULL)
            travle(p->right,deep+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        ans.clear();
        if(root == NULL)
            return ans;
        travle(root,1);
        return ans;
    }
};
