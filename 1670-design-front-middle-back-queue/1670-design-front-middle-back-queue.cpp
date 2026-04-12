class FrontMiddleBackQueue {
    deque<int> left, right;
    void balance() {
        if (left.size() > right.size() + 1) {
            right.push_front(left.back());
            left.pop_back();
        }
        if ( left.size() < right.size()) {
            left.push_back(right.front());
            right.pop_front();
        }
    }
public:
    FrontMiddleBackQueue() {
    }
    
    void pushFront(int val) {
        left.push_front(val);
        balance();
    }
    
    void pushMiddle(int val) {
        if (left.size() > right.size()) {
            right.push_front(left.back());
            left.pop_back();
        }
        left.push_back(val);
    }
    
    void pushBack(int val) {
        right.push_back(val);
        balance();
    }
    
    int popFront() {
        if (left.empty() && right.empty()) return -1;
        int tmp = left.front();
        left.pop_front();
        balance();
        return tmp;
    }
    
    int popMiddle() {
        if (left.empty() && right.empty()) return -1;
        int tmp = left.back();
        left.pop_back();
        balance();
        return tmp;
    }
    
    int popBack() {
        if (left.empty() && right.empty()) return -1;
        if (!right.empty()) {
            int tmp = right.back();
            right.pop_back();
            balance();
            return tmp;
        } else {
            int tmp = left.back();
            left.pop_back();
            balance();
            return tmp;
        }
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */