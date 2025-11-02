class Solution {
public:
    int n;
    unordered_map<int, int> stoneIndex;
    vector<vector<int>> dp;

    bool f(int i, int k, vector<int>& stones) {
        if (i == n - 1) return true;  // reached last stone
        if (dp[i][k] != -1) return dp[i][k];  // memoized result

        for (int jump = k - 1; jump <= k + 1; jump++) {
            if (jump <= 0) continue;
            int nextPos = stones[i] + jump;
            if (stoneIndex.find(nextPos) != stoneIndex.end()) {
                int nextIndex = stoneIndex[nextPos];
                if (f(nextIndex, jump, stones)) 
                    return dp[i][k] = true;
            }
        }

        return dp[i][k] = false;
    }

    bool canCross(vector<int>& stones) {
        n = stones.size();
        for (int i = 0; i < n; i++) {
            stoneIndex[stones[i]] = i;
        }

        dp.assign(n, vector<int>(n + 1, -1));

        if (stones[1] != 1) return false;  // frog must jump 1 on first move

        return f(1, 1, stones);
    }
};
