class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> freq;
        for(auto ch:s1)
            freq[ch]++;
        int l =0,r=0;
        for(int r = 0;r<s2.size();r++){
            if(r-l+1 > s1.size()){
                if(freq.count(s2[l]))
                    freq[s2[l]]++;
                l++;
            }
            if(freq.count(s2[r])){
                freq[s2[r]]--;
                // if(freq[s2[l]] == 0)
                //     freq.erase(s2[l]);
            }
            if(r>=s1.size()-1){
                bool res = true;
                for(auto &[ch,f]:freq){
                    if(f != 0){
                        res = false;
                        break;
                    }
                }
                if(res) return true;
            }
        }
        return false;   
    }
};
