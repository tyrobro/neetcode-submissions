class MedianFinder {
public:
    priority_queue<int> minHeap;
    priority_queue<int, vector<int>, greater<int>> maxHeap;

    MedianFinder() {}
    
    void addNum(int num) {
        minHeap.push(num);
        
        if(!maxHeap.empty() && minHeap.top() > maxHeap.top()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        if(minHeap.size() > maxHeap.size() +1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        if(minHeap.size() == maxHeap.size()) {
            return (maxHeap.top() + minHeap.top())/2.0;
        } else if (minHeap.size() > maxHeap.size()) {
            return minHeap.top();
        } else {
            return maxHeap.top();
        }
    }
};
