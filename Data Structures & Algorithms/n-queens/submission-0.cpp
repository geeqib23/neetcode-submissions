class Solution {
public:
    int N;
    set<int> sum,diff,col;
    vector<vector<string>> ans;
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        string def = "";
        for(int i = 0;i<n;i++) def += '.';
        vector<string> board(n,def);
        recur(0,board);
        return ans;
    }
    void recur(int i, vector<string> board){
        if(i == N) ans.push_back(board);
        for(int j = 0;j < N;j++){
            if(!sum.count(i+j) && !diff.count(j-i) && !col.count(j)){
                board[i][j] = 'Q';
                sum.insert(i+j);
                diff.insert(j-i);
                col.insert(j);
                recur(i+1,board);
                board[i][j] = '.';
                sum.erase(i+j);
                diff.erase(j-i);
                col.erase(j);
            }
        }
    }
};
