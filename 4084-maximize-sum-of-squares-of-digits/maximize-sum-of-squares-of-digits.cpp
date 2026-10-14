class Solution {
public:
    string maxSumOfSquares(int num, int sum) {

        if (sum < 1 || sum > 9 * num) {
            return "";
        }

        int noofnine = sum / 9;

        int rem = sum % 9;
        string s = "";

        while (noofnine--) {
            s += "9";
        }
        if (rem > 0) {
            s += to_string(rem);
        }
        int rem_length = num - s.length();
        while (rem_length--) {
            s += "0";
        }

        return s;
    }
};