class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int cnt[10] = {0};
        for (int d : digits) cnt[d]++;
        
        int total = 0;
        for (int h = 1; h <= 9; h++) {
            for (int t = 0; t <= 9; t++) {
                for (int u = 0; u <= 8; u += 2) {
                    int need[10] = {0};
                    need[h]++; need[t]++; need[u]++;
                    bool ok = true;
                    for (int i = 0; i < 10; i++) {
                        if (need[i] > cnt[i]) { ok = false; break; }
                    }
                    if (ok) total++;
                }
            }
        }
        return total;
    }
};