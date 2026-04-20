class TrieNode{
    public:
    unordered_map<char,TrieNode*> child;
    bool isEnd;
};
class WordDictionary {

    bool dfs(TrieNode* node, string word, int i){
        if(i == word.size()) 
            return node->isEnd;
        if(word[i] == '.'){
            bool res = false;
            for(auto &[ch,childNode]:node->child){
                res = res || dfs(childNode,word,i+1);
            }
            return res;
        }
        else{
            if(node->child.count(word[i]) == 0) return false;
            return dfs(node->child[word[i]],word,i+1);
        }
    }
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(auto &ch:word){
            if(!curr->child.count(ch))
                curr->child[ch] = new TrieNode();
            curr = curr->child[ch];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(root,word,0);
    }

};
