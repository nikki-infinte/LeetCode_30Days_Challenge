class MyQueue {
public:
    stack<int>s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s2.empty())
        {
            int elem = s2.top();
            s1.push(elem);
            s2.pop();
        }
        s2.push(x);

        while(!s1.empty())
        {
            int elem = s1.top();
            s2.push(elem);
            s1.pop();
        }
    }
    
    int pop() {
        int x = s2.top();
        s2.pop();
        return x;
    }
    
    int peek() {
        return s2.top();
    }
    
    bool empty() {
        return s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */