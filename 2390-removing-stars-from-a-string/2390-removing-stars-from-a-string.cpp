class Solution {
public:
    string removeStars(string s) {
        string stack;
        stack.reserve(s.size());

        for (char c : s) {
            if (c == '*') {
                stack.pop_back();
            } else {
                stack.push_back(c);
            }
        }

        return stack;
    }
};