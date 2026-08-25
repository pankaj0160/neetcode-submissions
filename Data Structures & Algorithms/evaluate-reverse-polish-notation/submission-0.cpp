class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int>stk;

        for(auto c : tokens) {
            if(c=="-") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push(b-a);
            }
            else if(c=="+"){
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push(b+a);
            }
            else if(c=="*"){
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push(b*a);
            }
            else if(c=="/"){
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push(b/a);
            }
            else stk.push(stoi(c));
        }
        return stk.top();
    }
};
