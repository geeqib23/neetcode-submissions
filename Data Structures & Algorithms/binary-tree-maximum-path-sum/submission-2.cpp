/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        helper(root);
        return res;
    }
    int helper(TreeNode* root){
        if(root == NULL) return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        int ret = root->val+max({0,left,right});
        res = max({res,ret,root->val+left+right});
        return ret;
    }

};
