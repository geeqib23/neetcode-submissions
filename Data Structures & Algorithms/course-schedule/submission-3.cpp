class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(n,vector<int>{});
        vector<int> indegree(n,0);
        for(auto &e:prerequisites){
            indegree[e[1]]++;
            g[e[0]].push_back(e[1]);
        }
        queue<int> q;
        for(int i = 0;i<n;i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        int c = 0;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            c++;
            for(auto c:g[v]){
                indegree[c]--;
                if(indegree[c] == 0)
                    q.push(c);
            }
        }
        return c == n;
    }
};
