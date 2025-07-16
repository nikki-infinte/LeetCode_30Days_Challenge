class MedianFinder {
public:
    priority_queue<int>maxheap;
    priority_queue< int,vector<int> , greater<int>>minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxheap.empty() || num < maxheap.top()){
            maxheap.push(num);
        }else{
            minheap.push(num);
        }

        if(maxheap.size() < minheap.size() ){
            maxheap.push(minheap.top());
            minheap.pop();
        }else if(maxheap.size() - minheap.size() > 1){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
    }
    
    double findMedian() {
        double ans =0;
        if(maxheap.size() == minheap.size()){
            ans = (maxheap.top()+minheap.top())/2.0;
        }
        else{
           ans = maxheap.top();
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