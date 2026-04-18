class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0;
        map<char,int> hs;
        int ans = 0;
        while(r < n){
            if(hs.count(s[r])){
                ans = max(ans,r-l);
                while(l <= hs[s[r]]){
                    hs.erase(s[l]);
                    l++;
                }
            }
            hs[s[r]] = r;
            r++;
        }
        ans = max(ans,r-l);
        return ans;
    }
};
