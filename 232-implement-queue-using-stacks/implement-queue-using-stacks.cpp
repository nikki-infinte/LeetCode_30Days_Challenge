class MyQueue {
public:
    stack<int>input,output;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        input.push(x);
        while(!output.empty()){
            input.push(output.top());
            output.pop();
        }
    }
    
    int pop() {
        int x = input.top();
        input.pop();
        return x;
    }
    
    int peek() {
        int x = input.top();
        return x;
    }
    
    bool empty() {
        return input.size() == 0;
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