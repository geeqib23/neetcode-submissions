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
    unordered_map<Node*,Node*> mp;
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        dfs(node);
        return mp[node];
    }
    void dfs(Node* node){
        Node* newNode = new Node(node->val);
        mp[node] = newNode;
        for(auto ch:node->neighbors){
            if(!mp.count(ch))
                dfs(ch);
            newNode->neighbors.push_back(mp[ch]);
        }
    }
};
