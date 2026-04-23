class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack<pair<int,int>> st;
        vector<int> nextGr(n,-1);
        for(int i = 0;i<n;i++){
            while(!st.empty() && temp[i]>st.top().first){
                nextGr[st.top().second] = i;
                st.pop();
            }
            st.push({temp[i],i});
        }
        for(int i = 0;i<n;i++){
            if(nextGr[i] == -1)
                nextGr[i] = 0;
            else
            nextGr[i] = nextGr[i]-i;
        }
        return nextGr;
    }
};
