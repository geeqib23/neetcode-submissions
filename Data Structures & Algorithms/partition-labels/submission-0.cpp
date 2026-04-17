class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> mx(26,-1);
        for(int i = 0;i<n;i++){
            mx[s[i]-'a'] = i;
        }
        int l = 0, r = 0,len = 1;
        vector<int> res;
        while(l<n && r<n){
            r = max(r,mx[s[l]-'a']);
            if(l == r){
                res.push_back(len);
                len = 1;
                l++;r++;
            }
            else{
                len++;
                l++;
            }
        }
        return res;
    }
};
