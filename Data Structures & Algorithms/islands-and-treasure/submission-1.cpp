class Solution {
public:
    vector<pair<int,int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        queue<pair<int,int>> q;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 0)
                    q.push({i,j});
            }
        }
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for(auto [dx,dy]:dir){
                int nx = x+dx;
                int ny = y+dy;
                if(nx >= n || nx < 0 || ny >= m || ny < 0) continue;
                if(grid[nx][ny] != INT_MAX) continue;
                grid[nx][ny] = grid[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
};
