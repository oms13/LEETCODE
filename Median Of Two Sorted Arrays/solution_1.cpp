#include <climits>
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;
        int cut1 = 0, cut2 = 0, l1 = 0, l2 = 0, r1 = 0 , r2 = 0;
        while (low <= high) {
            cut1 = (low + high) / 2;
            cut2 = (m + n + 1) / 2 - cut1;

            l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            r1 = (cut1 == m) ? INT_MAX : nums1[cut1];
            r2 = (cut2 == n) ? INT_MAX : nums2[cut2];

            if (l1 <= r2 && l2 <= r1) {
                if((m+n)%2 == 0)
                    return (max(l1,l2)+min(r1,r2))/2.0;
                else
                    return max(l1,l2);
            }
            else if(l1>r2)
                high = cut1 -1;
            else
                low = cut1 + 1;
        }
        return 0.0;
    }
};