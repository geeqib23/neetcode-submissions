class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n),post(n);
        pre[0] = nums[0];
        post[n-1] = nums[n-1];
        for(int i = 1;i<n;i++){
            pre[i] = nums[i]*pre[i-1];
            post[n-1-i] = nums[n-i-1]*post[n-i];
        }   
        vector<int> ans(n);
        for(int i = 0;i<n;i++)
            ans[i] = ((i>0) ? pre[i-1] : 1) * ((i<n-1)? post[i+1] : 1);
        return ans;
    }
};
