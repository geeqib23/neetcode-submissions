class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> hs;
        for(int i = 0;i < 9;i += 3){
            for(int j = 0;j < 9;j += 3){
                hs.clear();
                for(int k = i;k < i+3;k++){
                    for(int l = j;l < j+3;l++){
                        if(board[k][l] == '.') continue;
                        if(hs.count(board[k][l]))
                            return false;
                        hs.insert(board[k][l]);
                    }
                }
            }
        }
        for(int i = 0;i < 9;i++){
            hs.clear();
            for(int j = 0;j < 9;j++){
                if(board[i][j] == '.') continue;
                if(hs.count(board[i][j]))
                    return false;
                hs.insert(board[i][j]);
            }
        }
        for(int j = 0;j < 9;j++){
            hs.clear();
            for(int i = 0;i < 9;i++){
                if(board[i][j] == '.') continue;
                if(hs.count(board[i][j]))
                    return false;
                hs.insert(board[i][j]);
            }
        }
        return true;

    }
};
