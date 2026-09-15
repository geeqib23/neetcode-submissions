class DSU{
    vector<int> par;
    vector<int> sz;
public:
    DSU(int n){
        par.resize(n);
        sz.resize(n,1);
        for(int i = 0;i<n;i++)
            par[i] = i;
    }
    void unionize(int i,int j){
        i = find(i);
        j = find(j);
        if(i == j) return;
        if(sz[i] < sz[j]) swap(i,j);
        sz[i] += sz[j];
        par[j] = i;
    }
    int find(int i){
        if(par[i] == i) return i;
        else return par[i] = find(par[i]);
    }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for(int i =0;i<edges.size();i++){
            dsu.unionize(edges[i][0],edges[i][1]);
        }
        // int res = n;
        // for (auto& edge : edges) {
        //     if (dsu.unionSets(edge[0], edge[1])) { 
        //if already union return false if not do it, return true
        //         res--;
        //     }
        // }
        // return res;
        unordered_set<int> hs;
        for(int i = 0;i<n;i++){
            hs.insert(dsu.find(i));
        }
        return hs.size();
    }
};
