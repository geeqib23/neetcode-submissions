class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int,int>> st;
        vector<int> nextSmall(n,n);
        vector<int> prevSmall(n,-1);
        for(int i = 0;i<n;i++){
            while(!st.empty() && heights[i] < st.top().first){
                nextSmall[st.top().second] = i;
                st.pop();
            }
            if(!st.empty())
                prevSmall[i] = st.top().second;
            st.push({heights[i],i});
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            ans = max(ans,heights[i]*(nextSmall[i]-prevSmall[i]-1));
        }
        return ans;
    }
};
