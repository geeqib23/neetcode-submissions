class TrieNode{
    public:
    vector<TrieNode*> next;
    bool isEnd;
    TrieNode(){
        next.resize(26,NULL);
        isEnd = false;
    }
    void insert(string &s){
        TrieNode* curr = this;
        for(auto &ch:s){
            if(curr->next[ch-'a'] == NULL)
                curr->next[ch-'a'] = new TrieNode();
            curr = curr->next[ch-'a'];
        }
        curr->isEnd = true;
    }
};
class Solution {
public:
    TrieNode* root = new TrieNode();
    map<pair<int,TrieNode*>,bool> dp;
    bool wordBreak(string s, vector<string>& words) {
        for(auto &w:words){
            root->insert(w);
        }
        return helper(0,root,s);
    }
    bool helper(int i,TrieNode* curr, string &s){
        if(i == s.size()) return curr == root;
        if(curr->next[s[i]-'a'] == NULL)
            return false;

        if(dp.count({i,curr}))
            return dp[{i,curr}]; 
        
        TrieNode* nextNode = curr->next[s[i]-'a'];
        bool res = helper(i+1, nextNode, s);
        if(nextNode->isEnd)
            res = res || helper(i+1, root, s);
        
        return dp[{i,curr}] = res;
    }
};