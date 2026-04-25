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
    int res = 0;
    int goodNodes(TreeNode* root) {
        dfs(root,-101);
        return res;
    }
    void dfs(TreeNode* node,int mx){
        if(node == NULL) return;
        if(node->val >= mx)
            ++res;
        dfs(node->left,max(mx,node->val));
        dfs(node->right,max(mx,node->val));
    }
};
