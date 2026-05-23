class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> g(n+1,vector<pair<int,int>>{});
        for(auto &v:times){
            g[v[0]].push_back({v[1],v[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;
        vector<int> dist(n+1,INT_MAX);
        minHeap.push({0,k});
        dist[k] = 0;
        while(!minHeap.empty()){
            auto [d,node] = minHeap.top();
            minHeap.pop();
            if(d > dist[node]) continue; // dont forget this otherwise unnecessary reprocessing
            for(auto [ch,edge]:g[node]){
                int newDis = d+edge;
                if(newDis < dist[ch]){
                    dist[ch] = newDis;
                    minHeap.push({newDis,ch});
                }
            }
        }
        int ans = 0;
        for(int i = 1;i<=n;i++){
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};
