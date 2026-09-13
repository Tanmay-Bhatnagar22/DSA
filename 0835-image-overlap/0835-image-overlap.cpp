class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>> ones1, ones2;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) ones1.push_back({i, j});
                if (img2[i][j] == 1) ones2.push_back({i, j});
            }
        }
        
        unordered_map<int, int> count;
        int maxOverlap = 0;
        
        for (auto& p1 : ones1) {
            for (auto& p2 : ones2) {
                int dx = p1.first - p2.first;
                int dy = p1.second - p2.second;
                int key = dx * 200 + dy;
                count[key]++;
                maxOverlap = max(maxOverlap, count[key]);
            }
        }
        
        return maxOverlap;
    }
};