class TrieNode{
    public:
    vector<TrieNode*> child;
    int isEnd;
    TrieNode(){
        child.assign(26,NULL);
        isEnd = -1;
    }
     void addWord(string s,int ind){
        TrieNode* curr = this;
        for(int i = 0; i<s.size();i++){
            if(curr->child[s[i]-'a'] == NULL)
                curr->child[s[i]-'a'] = new TrieNode();
            curr = curr->child[s[i]-'a'];
        }
        curr->isEnd = ind;
    }
};
class Solution {
public:
//Q -> tranform a grid of characters into a trie of words(NOPE actually)
//Q -> search in a trie of words, for matrix possibilites
    vector<string> res;
    vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<bool>> vis;
    vector<string> findWords(vector<vector<char>>& matrix, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(int i = 0;i<words.size();i++){
            root->addWord(words[i],i);
        }
        int n = matrix.size(), m = matrix[0].size();
        vis.assign(n,vector<bool>(m,false));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                dfs(i,j,root,matrix,words);
            }
        }
        return res;
    }

    void dfs(int i,int j,TrieNode* node, vector<vector<char>> &matrix, vector<string> &words){
        TrieNode* nextNode = node->child[matrix[i][j]-'a'];
        if(nextNode == NULL) return;
        
        if(nextNode->isEnd != -1){
            res.push_back(words[nextNode->isEnd]);
            nextNode->isEnd = -1; // Avoid duplicates
        }

        vis[i][j] = true;
        for(auto &[dx,dy]:dir){
            int x = i+dx;
            int y = j+dy;
            if(x <0 || y < 0 || x >=matrix.size() || y >=matrix[0].size()) continue;
            if(vis[x][y]) continue;
            dfs(x,y,nextNode,matrix,words);
        }
        vis[i][j] = false;
    }
};


