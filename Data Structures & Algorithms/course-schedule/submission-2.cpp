class Solution {
public:
    vector<vector<int>> g;
    int n;
    set<int> vis;
    bool isCycle = false;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        g.resize(n,vector<int>{});
        for(auto &v:prerequisites){
            g[v[0]].push_back(v[1]);
        }
        for(int i = 0;i<n;i++){
            // vis.clear();
            dfs(i);
        }
        return !isCycle;

    }
    void dfs(int v){
        if(vis.find(v) != vis.end()) return;
        vis.insert(v);
        for(int c:g[v]){
            // cout << v << " " << c << endl;
            if(vis.find(c) != vis.end()){
                // cout << v << " " << c << endl;
                isCycle = true;
            }
            else{
                dfs(c);
            }
        }
        vis.erase(v);
    }
};
