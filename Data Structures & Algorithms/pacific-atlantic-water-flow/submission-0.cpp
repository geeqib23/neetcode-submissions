class Solution {
public:
    vector<pair<int,int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
    vector<vector<bool>> vis;
    vector<pair<int,int>> pacific,atlantic;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vis.resize(n,vector<bool>(m,false));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i == 0 || j == 0){
                    if(!vis[i][j])
                        dfs(i,j,n,m,heights,true);
                }
            }
        }
        // cout << endl <<endl;
        vis.assign(n,vector<bool>(m,false));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i == n-1 || j == m-1){
                    if(!vis[i][j])
                        dfs(i,j,n,m,heights,false);
                }
            }
        }
        vector<vector<int>> res;
        set<pair<int,int>> hs(pacific.begin(),pacific.end());
        for(auto &p:atlantic){
            if(hs.find(p) != hs.end())
                res.push_back(vector<int>{p.first,p.second});
        }
        return res;
    }
    void dfs(int i, int j,int n,int m, vector<vector<int>> heights,bool isPacific){
        // cout << i << " " << j << endl;
        vis[i][j] = true;
        if(isPacific)
            pacific.push_back({i,j});
        else 
            atlantic.push_back({i,j});
        for(auto &d:dir){
            int x = i+d.first;
            int y = j+d.second;
            if(x<0 || x >= n) continue;
            if(y<0 || y >= m) continue;
            if(vis[x][y]) continue;
            if(heights[x][y] < heights[i][j]) continue;
            dfs(x,y,n,m,heights,isPacific);
        }
    }
};
