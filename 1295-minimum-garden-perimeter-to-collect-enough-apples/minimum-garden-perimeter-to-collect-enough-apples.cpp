class Solution {
    using ll = long long;

    ll solve(ll l, ll cnt) {
        ll ans = 1LL * l * (l + 1) * cnt;
        return ans;
    }

public:
    long long minimumPerimeter(long long neededApples) {

        ll cnt = 2;
        ll ans = 0;
        for (ll axis = 1; axis <= 1e9; axis++) {
            ll l = 1LL * 2 * axis;

            if (solve(l, cnt) >= neededApples) {
                return 4 * l;
            }

            cnt++;
        }

        // return parimeter;

        return ans;
    }
};