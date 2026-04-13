class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(auto e:stones){
            maxHeap.push(e);
        }
        while(maxHeap.size() > 1){
            int f = maxHeap.top();
            maxHeap.pop();
            int s = maxHeap.top();
            maxHeap.pop();
            if(s<f){
                maxHeap.push(f-s);
            }
        }
        return maxHeap.size() == 1 ? maxHeap.top() : 0;
    }
};
