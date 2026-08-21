class TimeMap {
private:
    int binSearch(int l,int r,vector<pair<int,string>> &v, int tar){
        int res = -1;
        while(l<=r){
            int mid = (l+r)/2;
            if(v[mid].first > tar)
                r = mid-1;
            else {
                res = max(res,mid);
                l = mid+1;
            }
        }
        return res;
    }
public:
    unordered_map<string,vector<pair<int,string>> > hs;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        // if(hs.count(key)){
        //     if()
        // }
        hs[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(!hs.count(key)) return "";
        vector<pair<int,string>> &v = hs[key];
        int i = binSearch(0,v.size()-1,v,timestamp);
        if(i == -1) return "";
        return v[i].second;
    }
};
