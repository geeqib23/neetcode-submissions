/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        int res = 0;
        sort(intervals.begin(),intervals.end(),[](auto i1,auto i2){
            return i1.start < i2.start;
        });
        priority_queue<int,vector<int>,greater<>> minHeap;
        for(int i = 0;i<n;i++){
            int st = intervals[i].start;
            if(minHeap.empty() || minHeap.top() > st)
                minHeap.push(intervals[i].end);
            else{
                minHeap.pop();
                minHeap.push(intervals[i].end);
            }                
            res = max(res,(int)minHeap.size());
        }
        return res;
    }
};
