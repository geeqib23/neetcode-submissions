class MedianFinder {
public:
// 4 1 5 2
    // 4
    // 1 4

    // 1 maxHeap 4
    // 2 1 (maxHeap should have small elements) so we add 1. but then size imbalance
    
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<>> minHeap;
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(maxHeap.empty() || num <= maxHeap.top())
            maxHeap.push(num);
        else
            minHeap.push(num);
        if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        // if(minHeap.size() - maxHeap.size() > ){ 
        // Note : heap.size() returns unsigned int, cannot represent -ve integers, so wraps round
        if(minHeap.size() >maxHeap.size() ){ 
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if((minHeap.size()+maxHeap.size()) & 1)
            return maxHeap.top();
        else
            return (maxHeap.top()+minHeap.top())/2.0;

    }
};
