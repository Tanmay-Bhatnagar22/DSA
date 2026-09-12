#include <vector>
#include <array>
#include <algorithm>

using namespace std;

class Solution {
    struct Interval {
        int l, r;
        long long weight;
        int id;
    };

    struct State {
        long long weight = -1;
        vector<int> indices;

        bool isBetterThan(const State& other) const {
            if (weight != other.weight) {
                return weight > other.weight;
            }
            return indices < other.indices;
        }
    };

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

        // Sort by end time r
        sort(arr.begin(), arr.end(), [](const Interval& a, const Interval& b) {
            return a.r < b.r;
        });

        vector<int> end_times(n);
        for (int i = 0; i < n; ++i) {
            end_times[i] = arr[i].r;
        }

        // dp[i][k] -> using a prefix of intervals arr[0..i-1] choosing exactly k intervals
        vector<vector<State>> dp(n + 1, vector<State>(5));
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = {0, {}};
        }

        for (int i = 1; i <= n; ++i) {
            const auto& cur = arr[i - 1];

            // Find last interval that ends strictly before cur.l
            // end_times[prev_idx - 1] < cur.l
            int prev_idx = lower_bound(end_times.begin(), end_times.end(), cur.l) - end_times.begin();

            for (int k = 1; k <= 4; ++k) {
                // Option 1: Do not include arr[i - 1]
                State best_state = dp[i - 1][k];

                // Option 2: Include arr[i - 1]
                if (dp[prev_idx][k - 1].weight != -1) {
                    State candidate;
                    candidate.weight = dp[prev_idx][k - 1].weight + cur.weight;
                    candidate.indices = dp[prev_idx][k - 1].indices;
                    
                    // Insert and keep indices sorted
                    candidate.indices.insert(
                        lower_bound(candidate.indices.begin(), candidate.indices.end(), cur.id),
                        cur.id
                    );

                    if (candidate.isBetterThan(best_state)) {
                        best_state = move(candidate);
                    }
                }

                dp[i][k] = move(best_state);
            }
        }

        // Find the best among k = 1..4
        State ans = {0, {}};
        for (int k = 1; k <= 4; ++k) {
            if (dp[n][k].isBetterThan(ans)) {
                ans = dp[n][k];
            }
        }

        return ans.indices;
    }
};