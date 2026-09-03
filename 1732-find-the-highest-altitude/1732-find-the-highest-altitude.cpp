class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = 0, best = 0;
        for (int g : gain) {
            altitude += g;
            best = max(best, altitude);
        }
        return best;
    }
};