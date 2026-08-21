class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{')
                st.push(c);

            else {
                if (st.empty()) return false;

                char top = st.top();
                // check for matching paranthesis
                if ((c == ')' && top == '(') || (c == ']' && top == '[') ||
                    (c == '}' && top == '{'))
                    st.pop();

                else
                    return false;
            }
        }
        return st.empty();
    }
};
