class Solution {
public:
    vector<vector<int>> g;
    int n;
    vector<int> vis;
    bool isCycle = false;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        g.resize(n,vector<int>{});
        vis.assign(n,0);
        for(auto &v:prerequisites){
            g[v[1]].push_back(v[0]);
        }
        for(int i = 0;i<n;i++){
            // vis.clear();
            dfs(i);
        }
        return !isCycle;

    }
    void dfs(int v){
        if(vis[v] == 2) return;
        vis[v] = 1;
        for(int c:g[v]){
            // cout << v << " " << c << endl;
            if(vis[c] == 1){
                // cout << v << " " << c << endl;
                isCycle = true;
            }
            else{
                dfs(c);
            }
        }
        vis[v] = 2;
    }
};
