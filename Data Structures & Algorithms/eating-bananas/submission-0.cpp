class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1, r = *max_element(piles.begin(),piles.end());
        int ans = r;
        while(l<=r){
            int mid = l+(r-l)/2, hours = 0;
            for(auto &a:piles)
                hours += ceil((double)a/mid);
            if(hours > h){
                l = mid+1;
            }
            else if(hours <= h){
                r = mid -1;
                ans = min(ans,mid);
            }
        }
        return ans;
    }
};
