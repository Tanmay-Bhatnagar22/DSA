class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        // For each character, expand [first[c], last[c]] until it's self-contained
        vector<pair<int,int>> intervals;
        for (int c = 0; c < 26; c++) {
            if (first[c] == -1) continue;
            int start = first[c], end = last[c];
            bool valid = true;
            for (int i = start; i <= end; i++) {
                int ch = s[i] - 'a';
                if (first[ch] < start) { valid = false; break; }
                end = max(end, last[ch]);
            }
            if (valid) intervals.push_back({start, end});
        }

        // Greedily pick non-overlapping intervals, sorted by end (then start)
        sort(intervals.begin(), intervals.end(), [](const pair<int,int>& a, const pair<int,int>& b){
            if (a.second != b.second) return a.second < b.second;
            return a.first < b.first;
        });

        vector<string> res;
        int prevEnd = -1;
        for (auto& [start, end] : intervals) {
            if (start > prevEnd) {
                res.push_back(s.substr(start, end - start + 1));
                prevEnd = end;
            }
        }
        return res;
    }
};