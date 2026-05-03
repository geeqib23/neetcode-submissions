class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        set<string> hs = {"+","-","/","*"};
        for(int i = 0;i < tokens.size();i++){
            if(!st.empty()) cout << i << " " <<st.top() << endl;
            if(hs.count(tokens[i])){
                int n2 = st.top();
                st.pop();
                int n1 = st.top();
                st.pop();
                switch(tokens[i][0]){
                    case '+': st.push(n1+n2); break;
                    case '*': st.push(n1*n2); break;
                    case '-': st.push(n1-n2); break;
                    case '/': st.push(n1/n2); break;
                }
            }
            else
                st.push(stoi(tokens[i]));
        }
        return st.top();
    }
};
