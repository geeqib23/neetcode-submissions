class Solution {
public:
    vector<pair<int,int>> dir = {{0,-1},{0,1},{1,0},{-1,0}};
    vector<vector<bool>> vis;
    int n,m;
    bool flag = false;
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        vis.assign(n,vector<bool>(m,false));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                dfs(i,j,board,word,0);
                if(flag)
                    return true;
            }
        }
        return false;
    }
    void dfs(int i,int j,vector<vector<char>>& board,string &word, int ind){
        if(vis[i][j]) return;
        if(board[i][j] != word[ind]) return;
        if(ind == word.size() - 1){
            flag = true;
            return;
        }
        vis[i][j] = true;
        for(auto [dx,dy]:dir){
            int nx = i+dx;
            int ny = j+dy;
            if(nx<0 || nx >=n || ny < 0 || ny >=m) continue;
            dfs(nx,ny,board,word,ind+1);
            if(flag) return;
        }
        vis[i][j] = false;
    }
};