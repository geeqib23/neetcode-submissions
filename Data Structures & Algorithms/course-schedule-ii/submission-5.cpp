class Solution {
public:
// We do post order traversal of graph and then reverse
// otherwise if dfs is called on child first, it gets added before parent
    vector<vector<int>> g;
    int n;
    vector<int> vis;
    vector<int> res;
    bool isCycle = false;
   vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
        reverse(res.begin(), res.end());
        if(isCycle) return vector<int>{};
        else return res;

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
        res.push_back(v);
    }
};
