class Solution {
public:
    vector<vector<int>> dp;
    int countSubstrings(string s) {
        int n = s.size();
        dp.assign(n,vector<int>(n,-1));
        helper(0,n-1,s);
        int c = 0;
        for(auto &v:dp){
            for(auto &e:v){
                if(e == 1) c++;
                // cout << e << " ";
            }
            cout << endl;
        }
        return c;
    }

    bool helper(int i,int j,string &s){
        if(i<0 || j>=s.size()) return false;
        if(i == j) return dp[i][j] = true;
        if(dp[i][j] != -1) return dp[i][j];
        helper(i+1,j,s);
        helper(i,j-1,s);
        if(s[i] != s[j]){
            return dp[i][j] = false;
        }
        else{
            if(j-i == 1) 
                return dp[i][j] = true;
            return dp[i][j] = helper(i+1,j-1,s);
        }
    }
};
