class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks,
                    int additionalRocks) {
        int n = rocks.size();
        vector<int> diff(n, 0);

        for (int i = 0; i < n; i++) {
            diff[i] = capacity[i] - rocks[i];
        }

        sort(diff.begin(), diff.end());

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (diff[i] == 0) {
                cnt++;
            } else {

                if (additionalRocks >= diff[i]) {
                    additionalRocks -= diff[i];
                    cnt++;
                } else {
                    break;
                }
            }
        }

        return cnt;
    }
};