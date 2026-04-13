class KthLargest {
public:
    vector<int> stream;
    int K;
    KthLargest(int k, vector<int>& nums) {
        stream = nums;
        K = k;
    }
    
    int add(int val) {
        stream.push_back(val);
        sort(stream.begin(),stream.end(),greater<int>());
        return stream[K-1];
    }
};
