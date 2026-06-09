class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        int piv = 0;
        while(l<=r){
            int m = (l+r)/2;
            if((m-1>=0) && nums[m-1] > nums[m]){
                piv = m;
                break;
            }
            if(nums[m]<nums.back())
                r = m-1;
            else
                l = m+1;
        }
        int res1 = binSearch(0,piv-1,target,nums);
        if(res1 != -1)
            return res1; 
        int res2 = binSearch(piv,nums.size()-1,target,nums);
        return res2;
    }
    int binSearch(int l, int r,int target,vector<int> &nums){
        if(l>r) return -1;
        int m = (l+r)/2;
        if(nums[m] == target)
            return m;
        if(nums[m] > target)
            return binSearch(l,m-1,target,nums);
        else
            return binSearch(m+1,r,target,nums);
    }
};
