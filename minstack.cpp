ss MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        // do nothing
    }
    
    void push(int x) {
        if (minStack.size()==0) {
            minStack.push(pair<int, int> (x, x));
        }
        else {
            int m = getMin();
            if (x < m) {
                minStack.push(pair<int,int> (x, x));
            }
            else{
                minStack.push(pair<int, int> (x, m));
            }
        }
    }
    
    void pop() {
        minStack.pop();
    }
    
    int top() {
        return minStack.top().first;
    }
    
    int getMin() {
        return minStack.top().second;
    }
private:
    stack<pair<int, int>> minStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
