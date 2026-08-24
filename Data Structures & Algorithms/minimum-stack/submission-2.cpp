class MinStack {
   public:
    stack<int> stk;
    stack<int> helper;

    MinStack() {}

    void push(int val) {
        stk.push(val);
        val = min(val, helper.empty() ? val : helper.top());
        helper.push(val);
    }

    void pop() {
        stk.pop();
        helper.pop();
    }

    int top() { return stk.top(); }

    int getMin() { return helper.top(); }
};
