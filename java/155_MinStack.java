class MinStack {

    /** initialize your data structure here. */
    private Stack<Integer> stack;
    private Stack<Integer> minStack;
    public MinStack() {
        stack = new Stack<>();
        minStack = new Stack<>();
    }
    
    public void push(int x) {
        stack.push(x);
        if(!minStack.isEmpty()){
            int min = minStack.peek();
            if(x <= min){
                minStack.push(x);
            }
        }else{
            minStack.push(x);
        }
    }
    
    public void pop() {
        int x = stack.pop();
        if(!minStack.isEmpty()){
            if(x == minStack.peek()){
                minStack.pop();
            }
        }
    }
    
    public int top() {
        return stack.peek();
    }
    
    public int getMin() {
        return minStack.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
