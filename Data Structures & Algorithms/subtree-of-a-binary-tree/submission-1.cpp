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
    bool res = false;
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // if(dfs(root,subRoot) == NULL) return false;
        dfs(root,subRoot);
        return res;
    }
    void dfs(TreeNode* node,TreeNode* subRoot){
        if(node == NULL) return;
        if(node->val == subRoot->val){
            res = res || check(node,subRoot);
        }
        dfs(node->left,subRoot);
        dfs(node->right,subRoot);
        return;
    }
    bool check(TreeNode* node1,TreeNode* node2){
        if(node1 == NULL && node2 == NULL) return true;
        if(node1 == NULL || node2 == NULL) return false;
        if(node1->val != node2->val) return false;
        if(!check(node1->left,node2->left)) return false;
        if(!check(node1->right,node2->right)) return false;
        return true;
    }
};
