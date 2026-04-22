class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> freq(2001,0);
        for(auto &num:nums){
            freq[num+1000]++;
        }
        set<pair<int,int>> hs;
        for(int i = 0;i<2001;i++){
            if(freq[i] == 0) continue;
            hs.insert({freq[i],i-1000});
            if(hs.size()>k){
                hs.erase(hs.begin());
            }
        }
        vector<int> ans;
        for(auto &[key,value]:hs){
            ans.push_back(value);
        }
        return ans;
    }
};
