class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if(n == 0)
            return vector<vector<int>> {newInterval};
        vector<vector<int>> ans;
        bool flag = true;
        vector<int> startIndex(n);
        for(int i =0;auto &e:intervals){
            startIndex[i] = e[0];
            i++;
        }
        auto it = upper_bound(startIndex.begin(),startIndex.end(),newInterval[0]);
        int upperBound = it-startIndex.begin();
        // cout << upperBound;
        for(int i = 0;i<=n;i++){
            if(i == upperBound){
                if(ans.empty() || newInterval[0] > ans.back()[1]){
                    ans.push_back(newInterval);
                }
                else{
                    if(newInterval[1] > ans.back()[1])
                    ans.back()[1] = newInterval[1];
                }
            }
            if(i!=n){
                if(ans.empty() || intervals[i][0] > ans.back()[1]){
                    ans.push_back(intervals[i]);
                }
                else{
                    if(intervals[i][1] > ans.back()[1])
                        ans.back()[1] = intervals[i][1];
                }
            }
        }
        return ans;
    }
};
