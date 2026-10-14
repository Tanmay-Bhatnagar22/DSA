class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";

        string res;
        for (int i = 0; i < num; i++) {
            int d = min(9, sum);
            res += char('0' + d);
            sum -= d;
        }
        return res;
    }
};