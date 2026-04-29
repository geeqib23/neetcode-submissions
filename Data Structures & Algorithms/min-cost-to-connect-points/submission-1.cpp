class Solution {
public:
//PRIMS(n^2 logn)
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>> g(n,vector<pair<int,int>>{});
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int dist = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                g[i].push_back({j,dist});
                g[j].push_back({i,dist});
            }
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;
        vector<bool> vis(n,false);
        int total = 0,edges = -1;
        minHeap.push({0,0});
        while(!minHeap.empty()){
            auto [d,node] = minHeap.top();
            minHeap.pop();
            if(vis[node]) continue;
            vis[node] = true;
            edges++; 
            total += d;
            if(edges == n-1) break; // can also use vis as set, vis.size()==n
            for(auto &[ch,edge]:g[node]){
                minHeap.push({edge,ch});
            }
        } 
        return total;

    }
};
