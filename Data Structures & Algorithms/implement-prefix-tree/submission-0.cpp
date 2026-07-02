class TrieNode{
    public:
    bool isEnd;
    vector<TrieNode*> next;
    TrieNode(){
        isEnd = false;
        next.assign(26,NULL);
    }

};
class PrefixTree {
public:
    TrieNode* head;
    PrefixTree() {
        head = new TrieNode(); 
    }
    
    void insert(string word) {
        TrieNode* node = head;
        for(auto ch:word){
            if(node->next[ch-'a'] == NULL)
                node->next[ch-'a'] = new TrieNode();
            node = node->next[ch-'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = head;
        for(auto ch:word){
            if(node->next[ch-'a'] == NULL)
                return false;
            node = node->next[ch-'a'];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = head;
        for(auto ch:prefix){
            if(node->next[ch-'a'] == NULL)
                return false;
            node = node->next[ch-'a'];
        }
        return true;
    }
};
