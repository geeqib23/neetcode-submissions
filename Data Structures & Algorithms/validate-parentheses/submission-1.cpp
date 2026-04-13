class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char,char> mp = {{')','('},{']','['},{'}','{'} };
        for(auto &ch:s){
            if(ch == '(' || ch == '[' || ch =='{')
                st.push(ch);
            else{
                if(st.empty() || mp[ch] != st.top()) return false;
                else st.pop();
            }
        }
        return st.empty();
    }
};
