class Solution {
public:
    // for counting , think how many end at i 
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int prod = 1,l = 0,count = 0;
        for(int r = 0;r<nums.size();r++){
            prod *= nums[r];
            while(prod >= k && l<=r){
                prod = prod/nums[l];
                l++;
            }
            count += (r-l+1);
        }
        return count;
    }
};