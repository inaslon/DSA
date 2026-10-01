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
        int cnt = 0;

        while (i < m || j < n) {
            int temp;
            if (i == m) {
                temp = nums2[j++];
            } else if (j == n) {
                temp = nums1[i++];
            } else if (nums1[i] < nums2[j]) {
                temp = nums1[i++];
            } else {
                temp = nums2[j++];
            }

            if (cnt == k1) {
                x = temp;
            }
            if (cnt == k2) {
                y = temp;
            }

            cnt++;
        }

        return (x + y) / 2;
    }
};