class MinStack {
public:
    vector<pair<int,int>> stack;
    MinStack() {
    }
    
    void push(int val) {
        if(stack.empty()){
            stack.push_back({val,val});
        }
        else {
            if(stack.back().second > val){
                stack.push_back({val,val});
            }
            else {
                stack.push_back({val,stack.back().second});
            }
        }
    }
    
    void pop() {
        if(!stack.empty()){
            stack.pop_back();
        }
    }
    
    int top() {
        if(!stack.empty()){
            return stack.back().first;
        }
        return -1;
    }
    
    int getMin() {
        if(!stack.empty()){
            return stack.back().second;
        }
    }
};
