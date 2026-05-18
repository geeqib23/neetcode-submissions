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
    int helper(TreeNode* node){
        if(node == NULL) return 0;
        int leftSum = helper(node->left);
        int rightSum = helper(node->right);
        // cout << node->val << " " << leftSum << "  " << rightSum << endl;
        res = max({res,node->val,node->val+leftSum,node->val+rightSum,node->val+leftSum+rightSum});
        return max({node->val,node->val+leftSum,node->val+rightSum});
    }
};
