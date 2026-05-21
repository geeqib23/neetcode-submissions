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
    map<TreeNode*,TreeNode*> par;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root,NULL);
        set<TreeNode*> hs;
        while(p != NULL){
            hs.insert(p);
            p = par[p];
        }
        while(q != NULL){
            if(hs.count(q)){
                return q;
            }
            q = par[q];
        }
        return 0;
        
    }
    void dfs(TreeNode* node,TreeNode* p){
        if(node == NULL) return;
        par[node] = p;
        dfs(node->left,node);
        dfs(node->right,node);
    }
};
