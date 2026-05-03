class Solution {
public:
    vector<pair<int,int>> dir = {{0,-1},{0,1},{1,0},{-1,0}};
    void solve(vector<vector<char>>& board) {
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                if(i == 0 || j == 0 || i == board.size()-1 || j == board[0].size()-1){
                    if(board[i][j] == 'O')
                        dfs(i,j,board);
                }
            }
        }
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                if(board[i][j] == 'Y')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
    void dfs(int i,int j, vector<vector<char>> &board){
        // cout << i << " " << j << endl;
        board[i][j] = 'Y';
        for(auto &[dx,dy]:dir){
            int x = i+dx;
            int y = j+dy;
            if(x>=board.size() || y>=board[0].size() || x<0 || y < 0)
                continue;
            if(board[x][y] == 'X' || board[x][y] == 'Y')
                continue;
            dfs(x,y,board);
        }
    }
};
