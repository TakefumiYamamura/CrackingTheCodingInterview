class MinStack {
private:
    stack<int> minS;
    stack<int> s;
    
public:
    /*initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if(minS.empty() || getMin() >= x) minS.push(x);
    }
    
    void pop() {
        if(s.top() == getMin()){
            minS.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minS.top();
    }
};

/**
 Your MinStack object will be instantiated and called as such:
 MinStack obj = new MinStack();
 obj.push(x);
 obj.pop();
 int param_3 = obj.top();
 int param_4 = obj.getMin();
 */
