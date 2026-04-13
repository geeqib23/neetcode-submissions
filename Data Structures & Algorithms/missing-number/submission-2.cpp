class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int hypotheticalList = 0;
        for(int i = 0;i<=n;i++){
            hypotheticalList ^= i;
        }
        int realList = 0;
        for(int i = 0;i<n;i++){
            realList ^= nums[i];
        }
        return realList^hypotheticalList;
    }
};