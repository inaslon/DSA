class Solution {
    using ll = long long;
    vector<int> cand;
    ll K;
   bool ispossible(ll mid){
        ll cnt = 0;
        for(int i = 0;i<cand.size();i++){
            cnt += cand[i]/mid;
        }

        return cnt>= K;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        ll sum = accumulate(candies.begin(),candies.end(),0LL);
        if(sum<k) return 0;
        K = k;
        cand = candies;
        int ans = 0;
        ll low = 1,high = *max_element(candies.begin(),candies.end());

        while(low<=high){
            ll mid = low+ (high -low)/2;

            if(ispossible(mid)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return ans;

    }
};