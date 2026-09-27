class Solution {
public:
    string reverseParentheses(string s) {
        string result;
        stack<int> st;
        
        for (char c : s) {
            if (c == '(') {
                st.push(result.size());
            } else if (c == ')') {
                int start = st.top();
                st.pop();
                reverse(result.begin() + start, result.end());
            } else {
                result += c;
            }
        }
        
        return result;
    }
};