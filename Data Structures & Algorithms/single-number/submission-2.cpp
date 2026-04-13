class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int s = 0;
        for(auto x:nums){
            s = s^x;
        }
        return s;
    }
};
