class Solution {
public:
    vector<string> res;
    map<char,string> m = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}}; 
    vector<string> letterCombinations(string digits) {
        if(digits == "") return vector<string> {};
        helper(0,"", digits);
        return res;
    }
    void helper(int i,string s, string &digits){
        if(i == digits.size()){
            res.push_back(s);
            return;
        }
        for(auto ch:m[digits[i]]){
            s.push_back(ch);
            helper(i+1,s,digits);
            s.pop_back();
        }
    }
};
