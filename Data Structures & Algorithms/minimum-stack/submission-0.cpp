class MinStack {
public:
    vector<int> prefix;
    stack<int> st;
    MinStack() {

    }
    
    void push(int val) {
        st.push(val);
        int mn = prefix.empty() ? val : min(prefix.back(),val);
        prefix.push_back(mn);
    }
    
    void pop() {
        st.pop();
        prefix.pop_back();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return prefix.back();
    }
};
