class MinStack {
public:
    vector<int> stack; 
    MinStack() {
       
    }
    
    void push(int val) {
        stack.push_back(val);
    }
    
    void pop() {
       stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        auto min = min_element(stack.begin(), stack.end());
        return *min;
    }
};
