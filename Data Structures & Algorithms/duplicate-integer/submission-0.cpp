class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto e:nums){
            m[e]++;
            if(m[e] > 1) return true;
        }
        return false;
    }
};