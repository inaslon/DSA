class Solution {
    using ll = long long;

public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int n1 = n / 2;
        int n2 = n - n1;

        vector<int> left(n1);
        vector<int> right(n2);

        for (int i = 0; i < n1; i++) {
            left[i] = nums[i];
        }

        for (int i = 0; i < n2; i++) {
            right[i] = nums[n1 + i];
        }

        vector<ll> leftsum(1 << n1);
        vector<ll> rightsum(1 << n2);

        for (int mask = 0; mask < 1 << n1; mask++) {
            ll sum = 0;
            for (int i = 0; i < n1; i++) {
                if (mask & (1 << i)) {

                    sum += left[i];
                }
            }
            leftsum[mask] = sum;
        }

        for (int mask = 0; mask < 1 << n2; mask++) {
            ll sum = 0;
            for (int i = 0; i < n2; i++) {
                if (mask & (1 << i)) {

                    sum += right[i];
                }
            }
            rightsum[mask] = sum;
        }

        int ans = INT_MAX;

        sort(rightsum.begin(), rightsum.end());

        for (ll sum : leftsum) {

            int target = goal -sum;

            int l = lower_bound(rightsum.begin(), rightsum.end(), target) -
                       rightsum.begin();
           
            if(l<rightsum.size()){
                ans = min(ans, int(abs(sum+rightsum[l]-goal)));
            }

            if(l>0){
                  ans = min(ans, int(abs(sum+rightsum[l-1]-goal)));
            }

        }

        return ans;
    }
};