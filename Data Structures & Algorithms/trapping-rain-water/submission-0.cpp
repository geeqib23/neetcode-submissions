class Solution {
public:
//coudln't solve. look at each column's max and add them.
    int trap(vector<int>& heights) {
        int n = heights.size();
        vector<int> prefix(n),suffix(n);
        prefix[0] = 0;
        suffix[n-1] = 0;
        for(int i = 1;i<n;i++){
            prefix[i] = max(prefix[i-1],heights[i-1]);
            suffix[n-i-1] = max(suffix[n-i],heights[n-i]);
        }
        int total = 0;
        for(int i = 0;i<n;i++){
            int water = min(prefix[i],suffix[i])-heights[i];
            if(water>0)
                total += water;
        }
        return total;
    }
};
