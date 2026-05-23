class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        queue<pair<int,int>> q;
        int c = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 2)
                    q.push({i,j});
                else if(grid[i][j] == 1)
                    c++;
            }
        }
        if(c == 0) return 0;
        int min = -1;
        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0;i<sz;i++){
                auto [x,y] = q.front();
                q.pop();
                for(auto &[dx,dy] :dir){
                    int nx = x +dx;
                    int ny = y +dy;
                    if(nx < 0 || nx >=n || ny < 0 || ny >= m) continue;
                    if(grid[nx][ny] == 1){
                        c--;
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                    }
                } 
            }
            min++;
        }
        if(c > 0) return -1;
        return min;
    }
};
