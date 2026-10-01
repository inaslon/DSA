class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        double x = 0;
        double y = 0;

        int m = nums1.size();
        int n = nums2.size();
        int k1 = (m + n);
        int k2 = (k1) / 2;
        k1 = (k1 - 1) / 2;

        int i = 0, j = 0;

        for (int cnt = 0; cnt <= k2; cnt++) {
            int temp;

            int a = (i < m ? nums1[i] : INT_MAX);
            int b = (j < n ? nums2[j] : INT_MAX);
            if (a < b) {
                temp = a;
                i++;
            } else {
                temp = b;
                j++;
            }
            if (cnt == k1) {
                x = temp;
            }
            if (cnt == k2) {
                y = temp;
            }

          
        }

        return (x + y) / 2;
    }
};