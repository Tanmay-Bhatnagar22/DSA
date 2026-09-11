class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> strStack;
        string current = "";
        int num = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                countStack.push(num);
                strStack.push(current);
                num = 0;
                current = "";
            } else if (c == ']') {
                int k = countStack.top(); countStack.pop();
                string prev = strStack.top(); strStack.pop();
                string repeated = "";
                for (int i = 0; i < k; i++) repeated += current;
                current = prev + repeated;
            } else {
                current += c;
            }
        }
        
        return current;
    }
};