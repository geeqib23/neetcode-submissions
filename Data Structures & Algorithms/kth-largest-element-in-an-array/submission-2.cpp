class Solution {
public:
//selection sort algo
    int findKthLargest(vector<int>& nums, int k) {
        return helper(nums,k);
    }
    int helper(vector<int> v, int k){
        vector<int> left;
        vector<int> right;
        vector<int> equal;
        int pick = v[0];
        for(auto &a:v){
            if(a > pick) left.push_back(a);
            if(a == pick) equal.push_back(a);
            if(a < pick) right.push_back(a);
        }
        int l = left.size(), e = equal.size();
        if(l+e < k)
            return helper(right,k-l-e);
        else if(k>=l+1 && k <=l+e)
            return pick;
        else
            return helper(left,k);
    }
};
