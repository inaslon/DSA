class Solution {
    vector<vector<int>> mat;
    int m, n;
  int dp[105][105][205];
    bool solve(int i, int j, int sum) {
        if (sum < 0)
            return false;
        if (i >= m || j >= n)
            return false;

        if (i == m - 1 && j == n - 1) {
            sum += mat[i][j];
            return sum == 0;
        }
   
        if (dp[i][j][sum] !=-1) {
            return dp[i][j][sum];
        }
        bool down = solve(i + 1, j, sum + mat[i][j]);
        bool right = solve(i, j + 1, sum + mat[i][j]);

        return dp[i][j][sum] = down || right;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        mat.assign(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '(') {
                    mat[i][j] = 1;
                } else {
                    mat[i][j] = -1;
                }
            }
        }

        if ((m + n - 1) % 2 == 1) {
            return false;
        }

        memset(dp,-1,sizeof(dp));

        return solve(0, 0, 0);
    }
};