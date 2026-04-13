class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> stream;
    int K;
    KthLargest(int k, vector<int>& nums) {
        for(auto e:nums){
            stream.push(e);
            if(stream.size()>k){
                stream.pop();
            }
        }
        K = k;
    }
    
    int add(int val) {
        stream.push(val);
        if(stream.size()>K)
            stream.pop();
        return stream.top();
    }
};
