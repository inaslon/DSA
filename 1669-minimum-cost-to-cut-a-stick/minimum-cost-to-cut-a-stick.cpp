class Solution {

    vector<int> a;
    vector<vector<int>> dp;


    int solve(int i, int j) {
        if (j - i < 2)
            return 0;
    if(dp[i][j] !=-1){
        return dp[i][j];
    }
        int res = INT_MAX;
        for (int k = i + 1; k <= j - 1; k++) {
            int cost = a[j] - a[i] + solve(i, k) + solve(k, j);

            res = min(res, cost);
        }

        return dp[i][j] = res;
    }

public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        a = cuts;
        dp.assign(cuts.size()+1,vector<int>(cuts.size()+1,-1));
        return solve(0, a.size()-1);
    }
};