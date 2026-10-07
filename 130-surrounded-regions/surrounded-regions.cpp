class Solution {
    vector<pair<int, int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m, n;
    void dfs(int r, int c, vector<vector<char>>& board) {
        board[r][c] = '$';
        for (auto d : dir) {
            int nr = r + d.first;
            int nc = c + d.second;

            if (nr < 0 || nc < 0 || nr >= m || nc >= n ||
                board[nr][nc] != 'O') {
                continue;
            }

            dfs(nr, nc, board);
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                dfs(i, 0, board);
            }

            if (board[i][n - 1] == 'O') {
                dfs(i, n - 1, board);
            }
        }

        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') {
                dfs(0, j, board);
            }

            if (board[m - 1][j] == 'O') {
                dfs(m - 1, j, board);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }

                if(board[i][j] == '$'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};