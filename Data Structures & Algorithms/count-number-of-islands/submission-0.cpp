class DSU{
    vector<int> par;
    vector<int> size;
public:
    DSU(int n){
        par.resize(n);
        size.resize(n);
        for(int i = 0;i<n;i++){
            par[i] = i;
            size[i] = 1;
        }
    }
    bool setUnion(int i,int j){
        i = getPar(i);
        j = getPar(j);
        if(i == j) return true;
        if(size[i] < size[j])
            swap(i,j);
        size[i] += size[j];
        par[j] = i;
        return false;
    }
    int getPar(int i){
        if(i == par[i])
            return i;
        else
            return par[i] = getPar(par[i]);
    }
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        DSU* dsu = new DSU(m*n);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '0') continue;
                int x = i*m+j;
                if(i>0 && grid[i-1][j] == '1')
                    dsu->setUnion(x,(i-1)*m+j);
                if(i<n-1 && grid[i+1][j] == '1')
                    dsu->setUnion(x,(i+1)*m+j);
                if(j>0 && grid[i][j-1] == '1')
                    dsu->setUnion(x,i*m+(j-1));
                if(j<m-1 && grid[i][j+1] == '1')
                    dsu->setUnion(x,i*m+(j+1));
            }
        }
        unordered_set<int> hs;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '0') continue;
                hs.insert(dsu->getPar(i*m+j));
            }
        }
        return hs.size();
    }
};
