class Solution {
    int n;
    vector<int> a;
    int dp[100005][2][2];
    bool vis[100005][2][2];
    int solve(int idx, bool start, bool skipped) {
        if (idx >= n) {
            return start ? 0 : -1e9;
        }
        if (vis[idx][start][skipped]) {
            return dp[idx][start][skipped];
        }

        vis[idx][start][skipped] = true;
        int res = -1e9;
        if (!start) {

            res = max(a[idx] + solve(idx + 1, true, false),
                      solve(idx + 1, false, false));
        }

        else if (start) {
            int sres = -1e9;
            if (!skipped) {

                sres = max({a[idx] + solve(idx + 1, true, skipped),
                            solve(idx + 1, true, true), a[idx]});
            } else {
                sres = max(a[idx], a[idx] + solve(idx + 1, true, skipped));
            }

            res = max(sres, res);
        }

        return dp[idx][start][skipped] = res;
    }

public:
    int maximumSum(vector<int>& arr) {
        a = arr;
        n = a.size();

        // memset(vis, false, sizeof(vis));
        // return solve(0, false, false);

        int ans = arr[0];
        int curr = arr[0];
        int skipped = 0;
        for (int i = 1; i < n; i++) {
          int temp = curr;

          curr = max(arr[i],curr+arr[i]);

          skipped = max(temp,arr[i]+skipped);


            ans = max({ans,curr,skipped});
        }


        return ans;
    }
};