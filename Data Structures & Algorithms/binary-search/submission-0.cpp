class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(),hi=n-1,lo=0;
        while(lo<=hi){
            int m = (hi+lo)/2;
            if(target>nums[m])
                lo = m+1;
            else if(target<nums[m])
                hi = m-1;
            else return m;
        }
        return -1;
    }
};
