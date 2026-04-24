class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) return nums;
        int l = 0, r = 0;
        set<pair<int,int>, greater<>> hs;
        while(r < k){
            hs.insert({nums[r],r});
            r++;
        }
        r = k-1;
        vector<int> res(n-k+1);
        while(r<n){
            res[l] = hs.begin()->first;
            auto it = hs.find({nums[l],l});
            if(it != hs.end()){
                hs.erase(it);
            }
            l++;
            r++;
            if(r==n) break;
            hs.insert({nums[r],r});
        }
        return res;
    }
};
