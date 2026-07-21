class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> dp;

    int dfs(vector<vector<int>>& matrix, int r, int c) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();

        if (dp[r][c] != -1) {
            return dp[r][c];
        }

        int maxLen = 1;

        for (auto& d : directions) {
            int nr = r + d[0];
            int nc = c + d[1];

            if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && matrix[nr][nc] > matrix[r][c]) {
                maxLen = max(maxLen, 1 + dfs(matrix, nr, nc));
            }
        }

        return dp[r][c] = maxLen;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int ROWS = matrix.size(), COLS = matrix[0].size();
        dp = vector<vector<int>>(ROWS, vector<int>(COLS, -1));

        int ans = 0;
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                ans = max(ans, dfs(matrix, r, c));
            }
        }

        return ans;
    }
};