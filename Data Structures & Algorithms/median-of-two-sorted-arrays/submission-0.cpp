class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) swap(nums1,nums2);
        int n1= nums1.size(),n2 = nums2.size();
        int l = 0, r = n1;
        int totalHalf = (n1 + n2 + 1) / 2;
        while(l <= r){
            int chosen1 = (l + r) / 2;
            int chosen2 = totalHalf - chosen1;
            
            int l1 = (chosen1 == 0) ? INT_MIN : nums1[chosen1 - 1];
            int r1 = (chosen1 == n1) ? INT_MAX : nums1[chosen1];
            int l2 = (chosen2 == 0) ? INT_MIN : nums2[chosen2 - 1];
            int r2 = (chosen2 == n2) ? INT_MAX : nums2[chosen2];

            if(l1 <= r2 && l2 <= r1){
                if((n1 + n2) % 2 == 1) return max(l1, l2);
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else if(l1 > r2)
                r = chosen1 - 1;
            else
                l = chosen1 + 1;
        }
        return 0;
    }
};