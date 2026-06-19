class MyHashMap {
public:
    vector<int> hs;
    MyHashMap() {
        hs.assign(1e6+1,-1);
    }
    
    void put(int key, int value) {
        hs[key] = value;
    }
    
    int get(int key) {
        return hs[key];
    }
    
    void remove(int key) {
        hs[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */