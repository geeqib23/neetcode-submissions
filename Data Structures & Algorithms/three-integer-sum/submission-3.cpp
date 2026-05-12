class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,int> hs;
        int n = nums.size();
        for(int i =0;i<n;i++)
            hs[nums[i]]++;
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i =0;i<n;i++){
            hs[nums[i]]--;
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1;j<n;j++){
                hs[nums[j]]--;
                if(j>i+1 && nums[j] == nums[j-1]) continue;
                int third = -nums[i]-nums[j];
                if(third >= nums[j] && hs[third] > 0){
                    res.push_back(vector<int>{nums[i],nums[j],third});
                    // hs[third]--;
                    // if(hs.count(-nums[i]-third))
                    //     hs.erase(-nums[i]-third);
                    // if(hs.count(-nums[j]-third))
                    //     hs.erase(-nums[j]-third);
                }
            }
            for(int j = i+1;j<n;j++){
                hs[nums[j]]++;
            }
            hs[nums[i]]++;
        }
        return res;
    }
};
