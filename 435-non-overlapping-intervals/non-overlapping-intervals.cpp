class Solution {
    vector<vector<int>> intervals;
    int n;
    int dp[100001];
    int next(int idx){
        int low = idx+1;
        int high = n-1;
        int ans  = n;
        int end = intervals[idx][1];

        while(low<=high){
            int mid = low + (high-low)/2;


            if(end<=intervals[mid][0]){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return ans;
    }
    

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        this->intervals = intervals;
        n = intervals.size();
      vector<int> dp(n+1,0);

      for(int i = n-1;i>=0;i--){
        int nxt = next(i);
        int skip = dp[i+1];
        int take = dp[nxt]+1;

        dp[i] = max(take,skip);

      }

      return n - dp[0];
    }
};