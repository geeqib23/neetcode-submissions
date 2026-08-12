class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> check;
        if(nums.size() == 0) return 0; 
        int ans = 1, n = nums.size(); 
        for(auto &a : nums){
            check.insert(a);
        }
        for(auto &a : nums){
            if(check.count(a+1) && !check.count(a-1)){
                int i;
                for(i = a+1;i<a+n;i++){
                    if(!check.count(i))
                        break;
                }
                ans = max(ans,i-a);
            }
        }
        return ans;
    }
};
