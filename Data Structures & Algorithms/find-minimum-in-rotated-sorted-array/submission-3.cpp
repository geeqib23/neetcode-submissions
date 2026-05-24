class Solution {
public:
    int findMin(vector<int> &nums) {
        // if(nums.size() == 1) return nums[0];
        int l = 0, r = nums.size()-1;
        while(l<=r){
            if (nums[l] <= nums[r]) return nums[l];
            int m = (l+r)/2;
            if(m>0 && nums[m]<nums[m-1])
                return nums[m];
            if(nums[m] >= nums[l]){
                l = m+1;
            }
            else {
                r = m-1;
            }
        }
        return nums[0];
    }
};