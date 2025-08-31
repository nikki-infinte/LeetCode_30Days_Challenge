class MedianFinder {
public:
    priority_queue<int>maxHeap;
    priority_queue<int , vector<int> ,greater<int> >minHeap;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(maxHeap.empty() || num < maxHeap.top()){
            maxHeap.push(num);
        }else{
            minHeap.push(num);
        }


        if(maxHeap.size() < minHeap.size()){
            int elem = minHeap.top();
            minHeap.pop();
            maxHeap.push(elem);
        }else if(maxHeap.size() - minHeap.size() > 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        double ans = 0;
        if(maxHeap.size() == minHeap.size()){
            ans = (maxHeap.top() + minHeap.top())/2.0;
        }else{
            ans = maxHeap.top();
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */