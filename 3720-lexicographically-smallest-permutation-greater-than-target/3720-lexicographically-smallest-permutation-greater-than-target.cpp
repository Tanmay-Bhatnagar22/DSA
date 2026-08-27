class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;

        int matchLen = 0;
        for (int j = 0; j < n; j++) {
            int idx = target[j] - 'a';
            if (cnt[idx] > 0) {
                cnt[idx]--;
                matchLen++;
            } else {
                break;
            }
        }

        int U;
        if (matchLen == n) {
            U = n - 1;
            cnt[target[n - 1] - 'a']++;
        } else {
            U = matchLen;
        }

        for (int i = U; i >= 0; i--) {
            int foundChar = -1;
            for (int c = target[i] - 'a' + 1; c < 26; c++) {
                if (cnt[c] > 0) { foundChar = c; break; }
            }

            if (foundChar != -1) {
                cnt[foundChar]--;
                string result = target.substr(0, i);
                result += char('a' + foundChar);
                for (int c = 0; c < 26; c++) {
                    result.append(cnt[c], char('a' + c));
                }
                return result;
            }

            if (i > 0) {
                cnt[target[i - 1] - 'a']++;
            }
        }

        return "";
    }
};