class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> freq(2001,0);
        for(auto &num:nums){
            freq[num+1000]++;
        }
        // set<pair<int,int>> hs;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        for(int i = 0;i<2001;i++){
            if(freq[i] == 0) continue;
            // hs.insert({freq[i],i-1000});
            pq.push({freq[i],i-1000});
            if(pq.size()>k){
                pq.pop();
                // hs.erase(hs.begin());
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        // for(auto &[key,value]:hs){
        //     ans.push_back(value);
        // }
        return ans;
    }
};
