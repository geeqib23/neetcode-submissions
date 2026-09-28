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

// practice
class Solution {
public:
    unordered_map<int,int> mp;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        return func(0,0,preorder.size()-1,preorder);
    }
    // 0/0,3
    // left -> 1,1 (l+1, +(i-0-1))
    // right -> 2,3 (l+1+(i-0-1)+1,r) 
    //     left -> null
    //     right ->3,3
//WRONG I took l, r in preorder, cant calculate correct number of leftNum, And i didnt take root's index in preorder as argument.
    TreeNode* func(int i, int l, int r, vector<int>& preorder){
        // cout << l << " " << r << endl;
        if(l>r) return NULL;
        TreeNode* root = new TreeNode(preorder[i]);
        if(l == r) return root;
        int inorderInd = mp[preorder[i]];
        int numLeft = inorderInd-l;
        root->left = func(i+1,l,inorderInd-1,preorder);
        root->right = func(i+numLeft+1,inorderInd+1,r,preorder);
        return root;

    }
};
