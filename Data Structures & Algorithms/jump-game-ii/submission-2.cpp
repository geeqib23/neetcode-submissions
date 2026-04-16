class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        queue<int> q;
        vector<bool> vis(n,false);
        q.push(0);
        int ans = -1;
        while(!q.empty()){
            int sz = q.size();
            ans++;
            for(int i = 0;i<sz;i++){
                int top = q.front();
                if(top == n-1) return ans;
                q.pop();
                for(int j = top+1; j<=top+nums[top] && j<n;j++){
                    if(!vis[j]){
                        vis[j] = true;
                        q.push(j);
                    }
                }
            }
        }
        return ans;
    }
};
