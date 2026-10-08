class MyQueue {
    stack<int> st1;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stack<int> st2;
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        st2.push(x);
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
        int res = st1.top();
        st1.pop();
        return res;
    }
    
    int peek() {
        return st1.top();
    }
    
    bool empty() {
        return st1.empty();
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