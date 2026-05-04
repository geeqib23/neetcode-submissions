class Solution {
public:
    string res = "";
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,vector<char>> g;
        unordered_map<char,int> indegree;
        for (const auto& word : words) { //All nodes should be in graph in topo sort 
            for (char ch : word) {       // even if not involved in comparision
                if (!indegree.count(ch)) indegree[ch] = 0;
            }
        }
        for(int i = 0;i<words.size()-1;i++){
            int j = 0;
            int len1 = words[i].size(), len2 = words[i+1].size();
            bool found = false;
            while(j<min(len1,len2)){
                char ch1 = words[i][j];
                char ch2 = words[i+1][j];
                if(ch1 != ch2){
                    g[ch1].push_back(ch2);
                    // if(!indegree.count(ch1)) 
                    //     indegree[ch1] = 0;
                    // if(!indegree.count(ch2)) 
                    //     indegree[ch2] = 0;
                    indegree[ch2]++;
                    found = true;
                    break;
                }
                j++;
            }
            if(!found && len1>len2) return "";
        }
        queue<char> q;
        for(auto &[ch,in]:indegree){
            if(in == 0)
                q.push(ch);
        }
        while(!q.empty()){
            char p = q.front();
            res += p;
            q.pop();
            for(auto &child:g[p]){
                indegree[child]--;
                // cout << child << " " << indegree[child] << endl;
                if(indegree[child] == 0)
                    q.push(child);
            }
        }
        if(res.size() != indegree.size()) return "";
        return res;
    }
    
};
