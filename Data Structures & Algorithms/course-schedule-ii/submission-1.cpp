class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n,vector<int>{});
        vector<int> indegree(n);
        for(auto &v:edges){
            g[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }
        queue<int> q;
        for(int i=0 ;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> res;
        while(!q.empty()){
            int node = q.front();
            res.push_back(node);
            q.pop();
            for(auto ch:g[node]){
                indegree[ch]--;
                if(indegree[ch] == 0){
                    q.push(ch);
                }
            }
        }
        if(res.size() == n)
            return res;
        else
            return vector<int>{};
    }
};
