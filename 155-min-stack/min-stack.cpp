class MinStack {
public:
    long long minval;
    stack<long long> st;
    
    MinStack() {}
    
    void push(int val) {
        if(st.empty()) {
            minval = val;
            st.push(val);
        }
        else if(val < minval) {
            st.push(2LL * val - minval);   // force long long arithmetic
            minval = val;
        }
        else {
            st.push(val);
        }
    }
    
    void pop() {
        if(st.empty()) return;
        if(st.top() < minval) {
            minval = 2*minval - st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.empty()) return -1;
        if(st.top() < minval) return minval;
        return st.top();
    }
    
    int getMin() {
        return minval;
    }
};
