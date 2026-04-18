class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> price(n,1e9);
        price[src] = 0;
        for(int i = 0; i<k+1;i++){
            vector<int> temp = price;
            for(auto &edge:flights){
                int from = edge[0];
                int to = edge[1];
                int p = edge[2];
                if(price[from] == 1e9) continue;
                if(price[from]+p < temp[to]){
                    temp[to] = price[from]+p;
                }
            }
            price = temp;
        }
        return price[dst] == 1e9 ? - 1 : price[dst];
    }
};
