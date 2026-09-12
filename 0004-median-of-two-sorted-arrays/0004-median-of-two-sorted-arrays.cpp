class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Always perform binary search on the smaller array
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }

        int m = nums1.size();
        int n = nums2.size();

        int low = 0;
        int high = m;

        while (low <= high) {

            int i = (low + high) / 2;
            int j = (m + n + 1) / 2 - i;

            // Elements immediately to the left and right of partition
            int left1  = (i == 0) ? INT_MIN : nums1[i - 1];
            int right1 = (i == m) ? INT_MAX : nums1[i];

            int left2  = (j == 0) ? INT_MIN : nums2[j - 1];
            int right2 = (j == n) ? INT_MAX : nums2[j];

            // Correct partition
            if (left1 <= right2 && left2 <= right1) {

                // Total number of elements is odd
                if ((m + n) % 2 == 1) {
                    return max(left1, left2);
                }

                // Total number of elements is even
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            }

            // Partition in nums1 is too far right
            else if (left1 > right2) {
                high = i - 1;
            }

            // Partition in nums1 is too far left
            else {
                low = i + 1;
            }
        }

        return 0.0;
    }
};

