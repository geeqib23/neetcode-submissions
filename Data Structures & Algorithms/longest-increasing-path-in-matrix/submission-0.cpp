class Solution {
public:
    vector<vector<int>> pathLen;
    vector<pair<int,int>> dir = {{0,-1},{0,1},{1,0},{-1,0}};
    int n,m;
    int res = 1;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();    
        pathLen.assign(n,vector<int>(m,-1));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                dfs(i,j,matrix);
            }
        }
        return res;
    }

    int dfs(int i,int j, vector<vector<int>> &matrix){
        if(pathLen[i][j] != -1) return pathLen[i][j];
        int ret = 1;
        for(auto &[di,dj]:dir){
            int ni = i+di;
            int nj = j+dj;
            if(ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
            if(matrix[ni][nj] <= matrix[i][j]) continue;
            ret = max(ret,1+dfs(ni,nj,matrix));
        }
        res = max(res,ret);
        return pathLen[i][j] = ret;
    }
};
