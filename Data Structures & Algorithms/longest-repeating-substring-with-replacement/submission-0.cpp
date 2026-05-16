class Solution {
public:
//couldnt solve; was thinking to build such a string and then count, unless think of possibke substrings
//think how the limit of k can be used to eliminate substrings and optimize the solution 
    map<char,int> freq;
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0,r = 0,ans = 0;
        while(r<n){
            freq[s[r]]++;
            int diff = (r-l+1)-helper();
            if(diff <= k)
                ans = max(ans,r-l+1);
            while(diff > k){
                freq[s[l]]--;
                l++;
                diff = (r-l+1)-helper();
            }
            r++;
        }
        return ans;
    }
    int helper(){
        int mx = 0;
        for(auto &[ch,c]:freq)
            mx = max(mx,c);
        return mx;
    }
};
