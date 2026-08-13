class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0,res = 0;
        unordered_map<char,int> hs;
        for(int r = 0;r<s.size();r++){
            while(hs[s[r]] > 0){
                hs[s[l]]--;
                l++;
            }
            res = max(res,r-l+1);
            hs[s[r]]++;
        }
        return res;
    }
};
