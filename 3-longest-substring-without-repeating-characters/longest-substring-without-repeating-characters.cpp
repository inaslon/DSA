class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char, int> mp; // char ,freq

        int ans = 0;
        int l = 0;
        for (int r = 0; r < s.length(); r++) {
            mp[s[r]]++;
            while (mp[s[r]] > 1) {
                mp[s[l]]--;
                if(s[l] == 0){
                    mp.erase(s[l]);
                }
                l++;
            }

            ans = max(ans,r-l+1);
        }

        return ans;
    }
};