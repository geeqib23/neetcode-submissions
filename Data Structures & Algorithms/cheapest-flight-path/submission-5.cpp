class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k) {
        vector<vector<pair<int,int>>> g(n,vector<pair<int,int>>{});
        for(auto &v:flights){
            g[v[0]].push_back({v[1],v[2]});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        vector<vector<int>> dist(n,vector<int>(k+2,INT_MAX));
        dist[src][0] = 0;
        pq.push({0,src,0});
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int d = top[0],node= top[1],stops = top[2];
            if(node == dest) return d;
            // cout << node << " " <<top[0] << " " << stops <<endl;
            if(stops > k) continue;
            for(auto &[ch,edge]:g[node]){
                // cout << node << " child " << ch << " " << d+edge << " " << dist[ch][stops+1]<<endl;
                if(d + edge <= dist[ch][stops+1]){
                    dist[ch][stops+1] = d+edge;
                    pq.push({dist[ch][stops+1],ch,stops+1});
                }
            }
        }
        return -1;
    }
};
