class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(),m = matrix[0].size();
        int u = 0, d = n-1;
        int row = -1;
        while(u<=d){
            int mid = (u+d)/2;
            if(matrix[mid][0] <= target){
                row = max(row,mid);
                u = mid+1;
            }
            else{
                d = mid-1;
            }
        }
        if(row == -1) return false;
        int l = 0, r = m-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(matrix[row][mid] > target)
                r = mid-1;
            else if(matrix[row][mid] < target)
                l = mid+1;
            else 
            return true;
        }
        return false;


    }
};
