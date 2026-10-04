class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        int m = wordList[0].size();
        
        unordered_map<string,int> hs;
        for(int i = 0 ;i<n;i++){
            hs[wordList[i]] = i;
        }
        wordList.push_back(beginWord);
        queue<int> q;
        q.push(n);
        int lvl = 0;
        bool flag = false;
        while(!q.empty()){
            int k = q.size();
            lvl++;
            for(int i = 0;i<k;i++){
                int ind = q.front();
                q.pop();
                string t = wordList[ind];
                if(t == endWord){
                    flag = true;
                    return lvl;
                }
                for(int j = 0;j<m;j++){
                    for(char k = 'a';k<='z';k++){
                        t[j] = k;
                        if(hs.count(t)){
                            q.push(hs[t]);
                            hs.erase(t);
                        }
                    }
                    t[j] = wordList[ind][j];
                }
            }
        }
        return flag ? lvl : 0;

    }
};
