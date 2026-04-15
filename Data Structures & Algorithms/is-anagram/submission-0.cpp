class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26,0);
        for(auto &ch:s){
            freq[ch-97] += 1;
        }
        for(auto &ch:t){
            freq[ch-97]--;
        }
        for(auto e:freq){
            if(e != 0) return false;
        }
        return true;
    }
};
