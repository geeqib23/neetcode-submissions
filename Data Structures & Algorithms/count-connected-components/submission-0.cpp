class Solution {
public:
    vector<vector<int>> G;
    vector<int> vis;
    int countComponents(int n, vector<vector<int>>& edges) {
        G.resize(n,vector<int>{});
        vis.resize(n,-1);
        int c = 0;
        for(int i =0;i<edges.size();i++){
            G[edges[i][0]].push_back(edges[i][1]);
            G[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i = 0;i<n;i++){
            if(vis[i] == -1){
                dfs(i);
                c++;
            }
        }
        return c;
    }
    void dfs(int node){
        vis[node] = 1;
        for(auto &ch:G[node]){
            if(vis[ch] == -1)
                dfs(ch);
        }
    }
};
