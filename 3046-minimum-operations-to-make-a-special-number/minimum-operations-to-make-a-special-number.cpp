class Solution {
public:
    int minimumOperations(string num) {
        // divisible by 25 so last two digits should be  00, 50 ,25,75

        int n = num.size();

        int r1 = 1e9;

        int last0 = -1;
        int last_05 = -1;

        for (int i = n - 1; i >= 0; i--) {

            if (num[i] == '0' && last0 == -1) {
                last0 = i;
            }

            else if ((num[i] == '0' || num[i] == '5') && last0 != -1) {
                last_05 = i;
                break;
            }
        }

        if (last0 != -1 && last_05 != -1) {
            r1 = n - last0 - 1 + (last0 - last_05 - 1);
        }

        int r2 = 1e9;

        int last5 = -1;
        int last_27 = -1;

        for (int i = n - 1; i >= 0; i--) {

            if (num[i] == '5' && last5 == -1) {
                last5 = i;
            }

            else if ((num[i] == '2' || num[i] == '7') && last5 != -1) {
                last_27 = i;
                break;
            }
        }

        if (last5 != -1 && last_27 != -1) {
            r2 = n - last5 - 1 + (last5 - last_27 - 1);
        }

        int ans = min(r1, r2);
        int zeros = 0;
        for (char c : num) {
            if (c == '0')
                zeros++;
        }

        if (zeros > 0) {
            ans = min(ans, n - 1);
        }

        return min(ans,n);
    }
};