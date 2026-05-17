class DSU{
public:
    vector<int> par;
    vector<int> sz;
    DSU(int n){
        par.resize(n);
        sz.resize(n,1);
        for(int i = 0;i<n;i++)
            par[i] = i;
    }
    void unionize(int i,int j){
        i = find(i);
        j = find(j);
        if(i == j) return;
        if(sz[i] < sz[j]) swap(i,j);
        sz[i] += sz[j];
        par[j] = i;
    }
    int find(int i){
        if(par[i] == i) return i;
        else return par[i] = find(par[i]);
    }
};
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        DSU dsu(n*m+1);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 0) continue;
                int curr = i*m+j;
                if(i>0 && grid[i-1][j] == 1)
                    dsu.unionize(curr,(i-1)*m+j);
                if(j>0 && grid[i][j-1] == 1)
                    dsu.unionize(curr,i*m+(j-1));
                if(i<n-1 && grid[i+1][j] == 1)
                    dsu.unionize(curr,(i+1)*m+j);
                if(j<m-1 && grid[i][j+1] == 1)
                    dsu.unionize(curr,i*m+(j+1));
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){
                    ans = max(ans,dsu.sz[i*m+j]);
                }
            }
        }
        return ans;
    }
};
