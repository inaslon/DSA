class Solution {
    bool isok(vector<vector<int>>& tasks, int k) {

        for (auto& v : tasks) {
            if (v[1] > k) {
                return false;
            }
            if (k < 0) {
                return false;
            }

            k = k - v[0];
        }

        return true;
    }

public:
    int minimumEffort(vector<vector<int>>& tasks) {

        sort(tasks.begin(), tasks.end(), [](auto& a, auto& b) {
            if (a[1] - a[0] == b[1] - b[0]) {
                return a[0] > b[0];
            }
            return a[1] - a[0] > b[1] - b[0];
        });
        int ans;
        int low = 1;
        int high = 1e9;

        while (low <= high) {
            int mid = low + (high-low) / 2;

            if(isok(tasks,mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return ans;
    }
};