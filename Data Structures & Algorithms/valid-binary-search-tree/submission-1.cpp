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
    bool res = true;
    bool isValidBST(TreeNode* root) {
        dfs(root);
        return res;
    }
    pair<int,int> dfs(TreeNode* node){
        int mn=node->val,mx = node->val;
        if(!node->left && !node->right) return {mn,mx};
        if(node->left){
            auto leftSubtree = dfs(node->left);
            if(leftSubtree.second >= node->val){
                res = false;
            }
            mn = min(mn,leftSubtree.first);
            mx = max(mx,leftSubtree.second);
        }
        if(node->right){
            auto rightSubtree = dfs(node->right);
            if(rightSubtree.first <= node->val){
                res = false;
            }
            mn = min(mn,rightSubtree.first);
            mx = max(mx,rightSubtree.second);
        }
        return {mn,mx};
    }
};
