class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string result = "";
        int left = 0, ones = 0;
        
        for (int right = 0; right < n; right++) {
            if (s[right] == '1') ones++;
            
            while (ones > k) {
                if (s[left] == '1') ones--;
                left++;
            }
            
            while (left < right && s[left] == '0') left++;
            
            if (ones == k) {
                int len = right - left + 1;
                string cur = s.substr(left, len);
                if (result.empty() || len < (int)result.size() || 
                    (len == (int)result.size() && cur < result)) {
                    result = cur;
                }
            }
        }
        
        return result;
    }
};