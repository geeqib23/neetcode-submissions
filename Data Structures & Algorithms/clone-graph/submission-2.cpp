/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> vis;
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        Node* root = new Node(node->val);
        dfs(root,node);
        return root;
    }
    void dfs(Node* root,Node* node){
        cout << root->val << " " << node->val;
        vis[node] = root;
        for(auto ch:node->neighbors){
            if(vis.count(ch)) {
                root->neighbors.push_back(vis[ch]);  //IMP
                continue;
            }
            Node* newNode = new Node(ch->val);
            root->neighbors.push_back(newNode);
            dfs(newNode,ch);
        }
    }
};
