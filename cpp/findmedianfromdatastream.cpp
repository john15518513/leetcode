class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        minHeap.push(num);
        maxHeap.push(minHeap.top());
        minHeap.pop();
        if (minHeap.size() < maxHeap.size()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        if (minHeap.size() > maxHeap.size()) return minHeap.top();
        else return (minHeap.top() + maxHeap.top())/2.0;
    }
private:
    priority_queue<int, vector<int>, greater<int>> minHeap; //used for larger half
    priority_queue<int, vector<int>> maxHeap; // used for lower half
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
