class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        helper("",0,n);
        return res;
    }
    void helper(string s,int sum,int n){
        if(sum<0) return;
        if(n*2-s.size() < sum) return;
        if(s.size() == n*2){
            if(sum == 0)
                res.push_back(s);                
            return;
        }
        s += "(";
        helper(s,sum+1,n);
        s .pop_back();
        s += ")";
        helper(s,sum-1,n);
        s.pop_back();
    }
};
