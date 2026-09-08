class Solution {
public:
    int countCommas(int n) {
        long long total = 0;
        long long lower = 1;
        int d = 1;

        while (lower <= n) {
            long long upper = lower * 10 - 1;
            long long hi = std::min((long long)n, upper);
            long long count = hi - lower + 1;
            int commas = (d - 1) / 3;
            total += count * commas;

            lower = upper + 1;
            d++;
        }

        return (int)total;
    }
};