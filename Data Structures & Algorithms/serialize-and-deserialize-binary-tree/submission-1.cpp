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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        queue<TreeNode*> q;
        q.push(root);
        string res ="";
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL){
                res += "null,";
                // q.push(NULL);
                // q.push(NULL);
            }
            else{
                res += to_string(node->val)+',';
                q.push(node->left);
                q.push(node->right);
            }
        }
        res.pop_back();
        cout << res << endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL; 
        int n = data.size();
        vector<TreeNode*> v;
        string temp = "";
        for(int i =0;i<n;i++){
            if(data[i] == ','){
                if(temp == "null")
                    v.push_back(NULL);
                else
                    v.push_back(new TreeNode(stoi(temp)));
                temp = "";
            }
            else
                temp += data[i];
        }
        int j = 0;
        for(int i = 0;i<v.size();i++){
            if(v[i] == NULL){
                j += 2;
            }
            else{
                if(2*i+1-j < v.size())
                    v[i]->left = v[2*i+1-j]; 
                if(2*i+2-j < v.size())
                    v[i]->right = v[2*i+2-j]; 
            }
        }
        return v[0];
        // return NULL;
    }
};
