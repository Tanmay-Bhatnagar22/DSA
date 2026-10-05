class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for (char c : s) {
            if (c == '(') {
                st.push(0);
            } else {
                int inner = st.top();
                st.pop();
                st.top() += max(2 * inner, 1);
            }
        }
        return st.top();
    }
};