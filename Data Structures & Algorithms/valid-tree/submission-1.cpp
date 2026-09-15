class Solution {
public:
    vector<vector<int>> g;
    vector<int> vis;
    int c = 0;
    bool validTree(int n, vector<vector<int>>& edges) {
        g.assign(n,vector<int>{});
        vis.assign(n,-1);
        for(auto &v:edges){
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        bool res = dfs(0,-1);
        if(c<n) return false;
        return res;
    }
    bool dfs(int node,int par){
        vis[node] = 1;
        c++;
        for(int child:g[node]){
            if(child == par) continue;
            if(vis[child] == 1)
                return false;
            if(!dfs(child,node))
                return false;
        }
        return true;
    }
};

//dfs(node,par) from 0,-1
//mark vis[node] = 1 when entering
//if child == par , ignore
// if vis[child] == 1, cycle exists ,return false
// dfs(child,node)

