class Solution {
public:
    long long countCommas(long long n) {
        long long total = 0;
        long long lower = 1;
        long long upper = 9;
        int d = 1;

        while (lower <= n) {
            long long hi = min(upper, n);
            long long count = hi - lower + 1;
            long long commas = (d - 1) / 3;
            total += count * commas;

            d++;

            if (upper > (long long)4e18) break;
            lower = upper + 1;
            upper = upper * 10 + 9;
            if (upper < 0) upper = LLONG_MAX;
        }

        return total;
    }
};