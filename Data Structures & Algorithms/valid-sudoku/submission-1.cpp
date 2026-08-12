class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        vector<unordered_set<char>> col(n);
        vector<unordered_set<char>> row(n);
        map<string,unordered_set<char>> block;
        for(int i = 0;i< n;i++){
            for(int j = 0; j<n;j++){
                if(board[i][j] == '.')
                    continue;
                string s = to_string(i/3)+to_string(j/3);
                if(block[s].count(board[i][j]))
                    return false;
                if(col[i].count(board[i][j]))
                    return false;
                if(row[j].count(board[i][j]))
                    return false;
                col[i].insert(board[i][j]);
                block[s].insert(board[i][j]);
                row[j].insert(board[i][j]);
            }
        }
        return true;
    }
};
