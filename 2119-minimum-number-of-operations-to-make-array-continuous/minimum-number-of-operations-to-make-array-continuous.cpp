class Solution {
public:
    int minOperations(vector<int>& nums) {

      
        vector<int> arr;
        set<int> st(nums.begin(), nums.end());

        for (auto it : st) {
            arr.push_back(it);
        }

        int ans = INT_MAX;
        int n = nums.size();
        for (int i = 0; i < arr.size(); i++) {

            int min_ele = arr[i];

            int max_ele = arr[i] + n - 1;

            int idx =
                upper_bound(arr.begin() + i, arr.end(), max_ele) - arr.begin();

            ans = min(ans, n - (idx - i));
        }

        return ans;
    }
};