class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 00 02,  01 12,  02 22 
        // j-i,  (n-i-1)-j
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
