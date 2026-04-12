class MinStack {
    stack<int> min_st;
    stack<int> st;
public:
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        if (min_st.empty()) min_st.push(val);
        else if (val <= min_st.top()) min_st.push(val);
    }
    
    void pop() {
        if (st.top() == min_st.top()) {
            st.pop();
            min_st.pop();
        }
        else st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */