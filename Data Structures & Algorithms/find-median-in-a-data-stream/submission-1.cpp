class MedianFinder {
public:
//PRACTICE
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<>> minHeap;

    MedianFinder() {

    }
    
    void addNum(int num) {
        if(maxHeap.empty()){
            maxHeap.push(num);
            return;
        }
        if(maxHeap.size() - minHeap.size() == 1){
            if(num >= maxHeap.top())
                minHeap.push(num);
            else{
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
            }
        }
        else{
            if(num <= minHeap.top())
                maxHeap.push(num);
            else{
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
            }
        }
            
    }
    
    double findMedian() {
        if((maxHeap.size()+minHeap.size())&1)
            return maxHeap.top();
        else
            return (maxHeap.top()+minHeap.top())/2.0;
    }
};
// maxHeap - minHeap = 1
//     num > maxTop
//         insert to min
//     else
//         remove from max, insert into min
//         insert num to max

// max - min = 0
//     num < minTop
//         insert to max
//     else
//         remove from min, inset to max
//         insert num to min


        



