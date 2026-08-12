class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> marked;
        if(nums.size() == 0) return 0; 
        int ans = 1, n = nums.size(); 
        for(auto &a : nums){
            marked[a] = 0;
        }
        for(auto &a : nums){
            if(marked[a] == 0 && marked.count(a+1) && !marked.count(a-1)){
                int i;
                for(i = a+1;i<a+n;i++){
                    if(!marked.count(i))
                        break;
                    else
                        marked[i] = 1;
                }
                ans = max(ans,i-a);
            }
        }
        return ans;
    }
};
