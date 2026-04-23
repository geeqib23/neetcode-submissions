class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(),c = 0;
        for(int i = 0;i<n;i++){
            c++;
            int l = i-1;
            int r = i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                l--;
                r++;
                c++;
            }
        }
        for(int i = 0;i<n-1;i++){
            if(s[i] != s[i+1]) continue;
            c++;
            int l = i-1;
            int r = i+2;
            while(l>=0 && r<n && s[l]==s[r]){
                l--;
                r++;
                c++;
            }
        }
        return c;
    }
};
