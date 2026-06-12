class Solution {
public:
    vector<vector<int>> dp;
    bool isMatch(string s, string p) {
        dp.assign(s.size()+1,vector<int>(p.size()+1,-1));
        return helper(0,0,s,p) == 1;
    }

    int helper(int i,int j,string &s,string &p){
        if(i == s.size() && j == p.size()) return 1;
        // if(i >s.size()) return 0;
        if(j == p.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(j+1<p.size() && p[j+1] == '*'){
            if(p[j] == '.'){
                bool ret = helper(i+1,j+2,s,p);
                for(int k = i+1;k<s.size();k++){
                    if(s[k] == s[i+1])
                      ret = ret || helper(k+1,j+2,s,p);
                    else
                      break;
                }
                return dp[i][j] = ret ? 1 : 0;
            }
            else{
                bool ret = helper(i,j+2,s,p);
                for(int k = i;k<s.size();k++){
                    if(s[k] == s[i] && s[i] == p[j])
                        ret = ret || helper(k+1,j+2,s,p);
                    else
                        break;       
                }
                return dp[i][j] = ret ? 1 : 0;
            }
        }
        else if(p[j] == '.'){
            return dp[i][j] = helper(i+1,j+1,s,p);
        }
        else{
            if(s[i] != p[j]) return dp[i][j] = 0;
            else return dp[i][j] = helper(i+1,j+1,s,p);
        }
    }


};
