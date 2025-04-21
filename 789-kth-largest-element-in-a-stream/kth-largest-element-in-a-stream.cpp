class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>min_heap;
    int kth;
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for(auto a:nums)
        {
            min_heap.push(a);
        }
        
    }
    
    int add(int val) {
     
        min_heap.push(val);
        while(min_heap.size() > kth)
        {
           
            min_heap.pop();

        }
        int ans = min_heap.top();
      
        return ans;
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */