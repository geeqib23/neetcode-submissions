class DSU{
    public: 
    vector<int> par;
    vector<int> sz;
    DSU(int n){
        par.assign(n+1,0);
        for(int i = 1;i<=n;i++)
            par[i] = i;
        sz.assign(n+1,1);
    }
    int find(int v){
        if(par[v] == v) return v;
        else return par[v] = find(par[v]); 
    }
    bool isJoin(int v1, int v2){
        v1 = find(v1);
        v2 = find(v2);
        if(v1 == v2) return true;
        if(sz[v1] < sz[v2])
            swap(v1,v2);
        sz[v1] += sz[v2];
        par[v2] = v1;
        return false;
    }

};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size());
        for(auto &e:edges){
            if(dsu.isJoin(e[0],e[1])) return e;
        }
    }
};
