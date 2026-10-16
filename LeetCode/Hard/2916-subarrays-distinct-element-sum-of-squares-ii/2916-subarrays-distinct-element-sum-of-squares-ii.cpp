class Solution {
    static const int MOD = 1e9 + 7;
    vector<long long> sm, sq, lz;

    void applyNode(int o, int l, int r, long long v) {
        long long len = r - l + 1;
        sq[o] = (sq[o] + 2 * v % MOD * sm[o] % MOD + v * v % MOD * len) % MOD;
        sm[o] = (sm[o] + v * len) % MOD;
        lz[o] += v;
    }

    void pushDown(int o, int l, int r) {
        if (lz[o]) {
            int m = (l + r) / 2;
            applyNode(2 * o, l, m, lz[o]);
            applyNode(2 * o + 1, m + 1, r, lz[o]);
            lz[o] = 0;
        }
    }

    void update(int o, int l, int r, int ql, int qr, long long v) {
        if (ql <= l && r <= qr) {
            applyNode(o, l, r, v);
            return;
        }
        pushDown(o, l, r);
        int m = (l + r) / 2;
        if (ql <= m) update(2 * o, l, m, ql, qr, v);
        if (qr > m) update(2 * o + 1, m + 1, r, ql, qr, v);
        sm[o] = (sm[2 * o] + sm[2 * o + 1]) % MOD;
        sq[o] = (sq[2 * o] + sq[2 * o + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        sm.assign(4 * n, 0);
        sq.assign(4 * n, 0);
        lz.assign(4 * n, 0);

        unordered_map<int, int> last;
        long long ans = 0;

        for (int j = 0; j < n; j++) {
            int prev = last.count(nums[j]) ? last[nums[j]] : -1;
            update(1, 0, n - 1, prev + 1, j, 1);
            ans = (ans + sq[1]) % MOD;
            last[nums[j]] = j;
        }
        return (int)ans;
    }
};