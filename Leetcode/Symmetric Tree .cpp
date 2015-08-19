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
    void dfs(TreeNode  *p1,TreeNode *p2)
    {
        if(!flag) return ;
        if((p1 == NULL && p2 != NULL) || (p1 != NULL && p2 == NULL))
        {
            flag = false;
            return ;
        }
        if(p1 != NULL && p2 != NULL && p1->val != p2->val)
        {
            flag = false;
            return ;
        }
        if(p1 == NULL && p2 == NULL)
            return ;
        if(p1->left != NULL && p2->right != NULL)
            dfs(p1->left,p2->right);
        else if(p1->left == NULL && p2->right == NULL)
            ;
        else
        {
            flag = false;
            return ;
        }
        if(p1->right != NULL && p2->left != NULL)
            dfs(p1->right,p2->left);
        else if(p1->right == NULL && p2->left == NULL)
            ;
        else 
        {
            flag = false;
            return ;
        }
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        flag = true;
        dfs(root->left,root->right);
        return flag;
    }
};
