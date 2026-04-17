class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() <=1) return true;
        int l =0,r = 0;
        while(true){
            r = max(r,l+nums[l]);
            if(r >= nums.size()-1) return true;
            l++;
            if(l>r) return false;
        }
        return true;
    }
};
