class Solution {
    bool issubstr(int mid, string &a, string &b) {
        bool ans = true;
        string s;
        for (int i = 0; i < mid; i++)
            s += a;
        if (s.find(b) == string::npos) {
            ans = false;
        }

        return ans;
    }

public:
    int repeatedStringMatch(string a, string b) {

        int low = 1;
        int high = (b.length()+a.length() - 1)/a.length() + 1;

        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (issubstr(mid,a,b)){
                ans  = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return ans;
    }
};