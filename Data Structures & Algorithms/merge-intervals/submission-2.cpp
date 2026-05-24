class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        for(auto &e:intervals){
            if(ans.empty() || e[0] > ans.back()[1])
                ans.push_back(e);
            else{
                if(e[1] > ans.back()[1]){
                    ans.back()[1] = e[1];
                }
            }
        }
        return ans;
    }
};
