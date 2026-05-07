class Solution {
public:
//remember the way to spiral around a matrix
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int l = 0,r = matrix[0].size()-1;
        int top = 0,bottom = matrix.size()-1;
        vector<int> res;
        while(l<=r && top<=bottom){
            for(int i = l; i <= r; i++) res.push_back(matrix[top][i]);
            top++;
            for(int i = top; i <= bottom; i++) res.push_back(matrix[i][r]);
            r--;
            if(top <= bottom){
                for(int i = r; i >= l; i--) res.push_back(matrix[bottom][i]);
                bottom--;
            }
            if(l <= r){
                for(int i = bottom; i >= top; i--) res.push_back(matrix[i][l]);
                l++;
            }
        }
        
        return res;
    }
};