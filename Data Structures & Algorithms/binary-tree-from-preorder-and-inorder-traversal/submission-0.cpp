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
    unordered_map<int,int> ind;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            ind[inorder[i]] = i;
        }
        return build(0,0,inorder.size()-1,preorder,inorder);
    }
    TreeNode* build(int i,int l,int r,vector<int> &preorder,vector<int> &inorder){
        if(l > r)
            return NULL;
        TreeNode* node = new TreeNode(preorder[i]);
        if(l == r) return node;
        int in = ind[preorder[i]];
        int leftSize = in - l;
        node->left = build(i+1,l,in-1,preorder,inorder);
        node->right = build(i+leftSize+1,in+1,r,preorder,inorder);
        return node;
    }
};
