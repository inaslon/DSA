class Solution {
    using ll = long long;

public:
    int maxArea(vector<int>& height) {
        int n = height.size();
       

        int l = 0, r = n - 1;
        ll ans = 0;
        while (l < r) {
            if (height[l] < height[r]) {
                ans = max(ans, 1LL * height[l] * (r - l));
                l++;
            } else {

                ans = max(ans, 1LL * height[r] * (r - l));
                r--;
            }
        }
        return ans;
    }
};