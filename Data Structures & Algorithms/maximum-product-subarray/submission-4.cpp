class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prev = 0,res = -1e6;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 0){
                res = max({res,helper(prev,i-1,nums),0});
                prev = i+1;
            }
        }
        res = max(res,helper(prev,nums.size()-1,nums));
        return res;
    }
    int helper(int l,int r,vector<int> &nums){
        if(l>r) return -1e6;
        if(l == r) return nums[l];
        int c = 0,first = -1,prodPre = 1,last = -1,prodPost = 1, prod = 1;
        for(int i = l;i<=r;i++){
            prod = prod*nums[i];
            if(nums[i]<0){
                c++;
                if(first == -1){
                    first = i;
                    prodPre = prod;
                }
            }
        }
        if(c %2 == 0) return prod;
        else{
            for(int i = r;i>=l;i--){
                prodPost *= nums[i];
                if(nums[i]<0){
                    if(last == -1){
                        last = i;
                        break;
                    }
                }
            }
            return max(prod/prodPre,prod/prodPost);
        }
    }
};
