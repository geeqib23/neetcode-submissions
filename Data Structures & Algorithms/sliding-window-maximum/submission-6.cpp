class Solution {
public:
//Deque solution(similar logic to a heap soln- only remove element when it's necesssary)
//Monotonic Stack (dqeue) gives K largest elements till now.(keep in mind)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> res(n-k+1);
        for(int i = 0;i<n;i++){
            while(!dq.empty() && nums[i]>=nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1){
                while(!dq.empty() && dq.front()<i-(k-1))
                    dq.pop_front();
                res[i-(k-1)] = nums[dq.front()];
            }
        }
        return res;
    }
};
