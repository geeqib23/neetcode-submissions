class Solution {
public:
    vector<vector<string>> res = {};
    vector<vector<bool>> dp;
    vector<vector<string>> partition(string s) {
        int n = s.size();
        dp.assign(n,vector<bool>(n,false));
        for(int i = n-1;i>=0;i--){
            for(int j = i;j<n;j++){
                if(i == j){
                    dp[i][j] = true;
                }
                else if(j == i+1)
                    dp[i][j] = s[i] == s[j];
                else{
                    if(s[i] == s[j])
                        dp[i][j] = dp[i+1][j-1];
                    else
                        dp[i][j] = false; 
                }
            }
        }
        helper(0,s,vector<string>{});
        return res;
    }

    void helper(int i,string &s,vector<string> temp){
        if(i == s.size()){
            res.push_back(temp);
            return;
        }
        for(int j = i;j<s.size();j++){
            if(dp[i][j]){
                temp.push_back(s.substr(i, j-i+1));
                helper(j+1,s,temp);
                temp.pop_back();
            }
        }
    }
};
