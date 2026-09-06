class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> count;
        for (int num : arr) {
            count[num]++;
        }
        
        unordered_set<int> seen;
        for (auto& [val, freq] : count) {
            if (seen.count(freq)) return false;
            seen.insert(freq);
        }
        
        return true;
    }
};