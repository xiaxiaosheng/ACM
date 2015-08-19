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
    bool flag;
    int count(TreeNode* p)
    {
        if(!flag || p == NULL) return 0;
        if(p->left == NULL && p->right == NULL)
            return 1;
        int a = count(p->left),b = count(p->right);
        if(abs(a-b) > 1)
            flag = false;
        return max(a,b) + 1;
    }
    bool isBalanced(TreeNode* root) {
        flag = true;
        count(root);
        return flag;
    }
};
