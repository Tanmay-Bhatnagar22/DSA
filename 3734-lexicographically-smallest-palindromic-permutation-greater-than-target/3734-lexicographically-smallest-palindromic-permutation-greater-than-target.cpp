class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;

        int oddCount = 0, oddChar = -1;
        for (int i = 0; i < 26; i++)
            if (cnt[i] % 2 == 1) { oddCount++; oddChar = i; }

        if ((n % 2 == 0 && oddCount > 0) || (n % 2 == 1 && oddCount != 1))
            return "";

        bool odd = (n % 2 == 1);
        int m = (n + 1) / 2;
        int midChar = odd ? oddChar : -1;

        vector<int> half(26, 0);
        for (int i = 0; i < 26; i++) {
            if (odd && i == oddChar) half[i] = (cnt[i] - 1) / 2;
            else half[i] = cnt[i] / 2;
        }

        {
            vector<int> hc = half;
            bool feasible = true;
            for (int i = 0; i < m; i++) {
                int c = target[i] - 'a';
                if (odd && i == m - 1) {
                    if (c != midChar) { feasible = false; break; }
                } else {
                    if (hc[c] <= 0) { feasible = false; break; }
                    hc[c]--;
                }
            }
            if (feasible) {
                string H = target.substr(0, m);
                string P = buildPalindrome(H, n);
                if (P > target) return P;
            }
        }

        vector<vector<int>> states;
        vector<int> cur = half;
        states.push_back(cur);
        int failPos = -1;

        for (int i = 0; i < m; i++) {
            int c = target[i] - 'a';
            if (odd && i == m - 1) {
                if (c == midChar) {
                    states.push_back(cur);
                    continue;
                } else {
                    failPos = i;
                    break;
                }
            } else {
                if (cur[c] <= 0) { failPos = i; break; }
                cur[c]--;
                states.push_back(cur);
            }
        }
        if (failPos == -1) failPos = m;

        string H(m, ' ');
        for (int i = 0; i < failPos && i < m; i++) H[i] = target[i];

        bool found = false;
        int lastFree = odd ? m - 2 : m - 1;

        for (int k = min(failPos, m - 1); k >= 0 && !found; k--) {
            vector<int>& st = states[k];
            int targetChar = target[k] - 'a';

            if (odd && k == m - 1) {
                if (midChar > targetChar) {
                    H[k] = 'a' + midChar;
                    found = true;
                }
            } else {
                int chosen = -1;
                for (int c = targetChar + 1; c < 26; c++) {
                    if (st[c] > 0) { chosen = c; break; }
                }
                if (chosen != -1) {
                    vector<int> rem = st;
                    rem[chosen]--;
                    H[k] = 'a' + chosen;

                    int pos = k + 1;
                    for (int c = 0; c < 26 && pos <= lastFree; c++) {
                        while (rem[c] > 0 && pos <= lastFree) {
                            H[pos++] = 'a' + c;
                            rem[c]--;
                        }
                    }
                    if (odd) H[m - 1] = 'a' + midChar;

                    found = true;
                }
            }
        }

        if (!found) return "";
        return buildPalindrome(H, n);
    }

private:
    string buildPalindrome(const string& H, int n) {
        string P(n, ' ');
        int m = H.size();
        for (int i = 0; i < m; i++) {
            P[i] = H[i];
            P[n - 1 - i] = H[i];
        }
        return P;
    }
};