class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = queries.size();
        vector<pair<int,int>> quer(n);
        for(int i = 0;i<n;i++)
            quer[i] = {queries[i],i};
        sort(intervals.begin(),intervals.end());
        sort(quer.begin(),quer.end());
        vector<int> res(n);
        int j = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> minHeap;
        for(int i = 0;i<n;i++){
            int a = quer[i].first;
            while(j<intervals.size() && intervals[j][0] <= a){
                minHeap.push({intervals[j][1]-intervals[j][0]+1, intervals[j][1]});
                j++;
            }
            while(!minHeap.empty() && minHeap.top().second < a){
                minHeap.pop();
            }
            if(minHeap.empty())
                res[quer[i].second] = -1;
            else
                res[quer[i].second] = minHeap.top().first;
        }
        return res;
    }
};
