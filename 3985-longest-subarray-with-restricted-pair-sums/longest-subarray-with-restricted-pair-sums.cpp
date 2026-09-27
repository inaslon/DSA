class Solution {
    unordered_map<int, int> mp; // num, freq
    // unordered_map<int, vector<int>> idxs; // num, indexes

    bool isvalid(int x) {

        for (auto& [a, freq] : mp) {
            int b = x - a;
            int c = x + a;

            if (mp.count(b)) {
                if (a != b) {
                    return false;
                }
                if (freq >= 2) {
                    return false;
                }
            }

            if (mp.count(c)) {
                return false;
            }
        }
        return true;
    }

public:
    int maxSubarray(vector<int>& nums) {

        int n = nums.size();
        int l = 0;
        int len = 0;
        for (int r = 0; r < n; r++) {
            int x = nums[r];

            while(!isvalid(x)) {

                mp[nums[l]]--;
                if(mp[nums[l]] == 0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            mp[x]++;
            len = max(len, r - l + 1);
        }

        return len;
    }
};