class MinStack {
public:
    stack<long long> stk;
    long long mn = 0;

    MinStack() {}

    void push(int val) {
        if (stk.empty()) {
            stk.push(0);
            mn = val;
        }
        else {
            stk.push((long long)val - mn);

            if (val < mn)
                mn = val;
        }
    }

    void pop() {
        if (stk.empty()) return;

        long long popped = stk.top();

        if (popped < 0)
            mn -= popped;

        stk.pop();
    }

    int top() {
        if (stk.top() > 0)
            return (int)(stk.top() + mn);
        else
            return (int)mn;
    }

    int getMin() {
        return (int)mn;
    }
};