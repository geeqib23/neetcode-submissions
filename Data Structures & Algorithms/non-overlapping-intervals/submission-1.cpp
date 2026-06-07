class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int last = intervals[0][1], c= 0;
        for(int i = 1;i<intervals.size();i++){
            if(intervals[i][0] >= last){
                last = intervals[i][1];
            } 
            else{
                c++;
                if(intervals[i][1] < last)
                    last = intervals[i][1];
            }
        }
        return c;
    }
};
