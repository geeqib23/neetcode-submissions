class Solution {
public:
    vector<vector<vector<int>>> dp;
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        if(s3.size() != m+n) return false;
        dp.assign(n + 1, vector<vector<int>>(m + 1, vector<int>(3, -1)));
        return helper(0,0,0,s1,s2,s3);
    }
    bool helper(int i1,int i2, int which,string &s1,string &s2,string &s3){
        if(i1 == s1.size() && i2 == s2.size())
            return true;
        if(dp[i1][i2][which] != -1) return dp[i1][i2][which] == 1;
        bool res = false;
        if(which == 0 || which == 1){
            for(int l = 1;l<=s1.size()-i1 && l<=s3.size()-i1-i2;l++){
                if(s3.substr(i1+i2,l) == s1.substr(i1,l))
                    res = res || helper(i1+l,i2,2,s1,s2,s3);
                else
                    break;
            }
        }
        if(which == 0 || which == 2){
            for(int l = 1;l<=s2.size()-i2 && l<=s3.size()-i1-i2;l++){
                if(s3.substr(i1+i2,l) == s2.substr(i2,l))
                    res = res || helper(i1,i2+l,1,s1,s2,s3);
                else
                    break;
            }
        }
        dp[i1][i2][which] = res ? 1 : 0;
        cout << i1 << " " << i2 << " " << which <<  " " << dp[i1][i2][which] << endl;
        return res;
    }
};
