class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
//couldnt solve, reverse columnwise(flip) and transpose
//Transposing only requires iterating over upper triangle and swapping.
        int n = matrix.size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n/2;j++){
                swap(matrix[j][i],matrix[n-1-j][i]);
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};
