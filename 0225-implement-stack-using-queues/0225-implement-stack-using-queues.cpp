class MyStack {
    queue<int> queue1;
    queue<int> queue2;
public:
    MyStack() {
    }
    
    void push(int x) {
        while(!queue1.empty()) {
            queue2.push(queue1.front());
            queue1.pop();
        }
        queue1.push(x);
        while(!queue2.empty()) {
            queue1.push(queue2.front());
            queue2.pop();
        }
    }
    
    int pop() {
        int num = queue1.front();
        queue1.pop();
        return num;
    }
    
    int top() {
        int num = queue1.front();
        return num;
    }
    
    bool empty() {
        return queue1.empty() && queue2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */