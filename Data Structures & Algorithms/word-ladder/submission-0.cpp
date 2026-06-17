class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        unordered_map<int,vector<int>> g;
        int n = wordList.size();
        int m = wordList[0].size();
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int c = 0;
                for(int k = 0;k<m;k++){
                    if(wordList[i][k] != wordList[j][k])
                        c++;
                }   
                if(c == 1){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        queue<int> q;
        q.push(n-1);
        int d = 0;
        vector<bool> vis(n+1);
        while(!q.empty()){
            int sz = q.size();
            d++;
            for(int i = 0;i<sz;i++){
                int node = q.front();
                vis[node] = true;
                q.pop();
                // cout << wordList[node] << endl;
                if(wordList[node] == endWord)
                    return d;
                for(auto ch:g[node]){
                    if(!vis[ch])
                        q.push(ch);
                }
            }
        }
        return 0;    
    }
};
