class Solution {
    vector<int> w;
    int n;
    bool ispossible(int limit, int days) {

        int curr = 0;
        int d = 1;
        for (int i = 0; i < n; i++) {
            if (curr + w[i] <= limit) {
                curr += w[i];
            } else {
                curr = w[i];
                d++;
            }
        }
        return d <= days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        w = weights;
        n = w.size();
        int sum = accumulate(weights.begin(), weights.end(), 0);

        int low = *max_element(weights.begin(),weights.end()), high = sum;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (ispossible(mid, days)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};