class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            int letterValue = 26 - (s[i] - 'a');
            sum += letterValue * (i + 1);
        }
        return sum;
    }
};