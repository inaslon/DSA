class Solution {
    using ll = long long;

public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = nums[i] * nums[i];
        }

        sort(a.begin(), a.end());

        int mid = n / 2;
        ll minus = 0;
        for (int i = 0; i < mid; i++) {

            minus += a[i];
        }

        ll add = 0;
        for (int i = mid; i < n; i++) {
            add += a[i];
        }

        return add - minus;
    }
};