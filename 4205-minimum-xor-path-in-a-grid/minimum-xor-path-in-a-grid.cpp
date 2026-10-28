class Solution {
    int n, m;
    vector<vector<int>> grid;
    vector<vector<vector<int>>> dp;
    int solve(int i, int j, int x) {

        if (i == n - 1 && j == m - 1) {
            return x ^ grid[i][j];
        }
        if (i >= n || j >= m)
            return 1e9;

        if(dp[i][j][x] !=-1){
            return dp[i][j][x];
        }    

        int right = solve(i, j + 1, x ^ grid[i][j]);
        int down = solve(i + 1, j, x ^ grid[i][j]);

        return dp[i][j][x] =  min(right, down);
    }

public:
    int minCost(vector<vector<int>>& grid) {

        this->grid = grid;
        n = grid.size();
        m = grid[0].size();
        dp.assign(n+1,vector<vector<int>>(m+1,vector<int>(1024,-1)));
        return solve(0, 0, 0);
    }
};