class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) swap(nums1, nums2); // len1 is always <= len2
        int minElementsPickedFromNums1 = 0, maxElementsPickedFromNums1 = nums1.size();
        int l = minElementsPickedFromNums1, r = maxElementsPickedFromNums1, half = (nums1.size()+nums2.size()+1)/2;
        int L = nums1.size()+nums2.size();
        while(l <= r) {
            int m = l+(r-l)/2;
            int numele1 = m, numele2 = half-m;
            int leftidx1 = numele1-1, leftidx2 = numele2-1;
            int rightidx1 = numele1, rightidx2 = numele2;
            int left1 = INT_MIN, left2 = INT_MIN, right1 = INT_MAX, right2 = INT_MAX;
            if(leftidx1 >= 0) left1 = nums1[leftidx1];
            if(leftidx2 >= 0) left2 = nums2[leftidx2];
            if(rightidx1 < nums1.size()) right1 = nums1[rightidx1];
            if(rightidx2 < nums2.size()) right2 = nums2[rightidx2];
            if(left1 <= right2 && left2 <= right1) {
                if(L%2 == 0) return (max(left1, left2)+min(right1,right2))/2.0;
                else return max(left1,left2);
            } else if(left1 > right2) {
                r = m-1;
            } else if(right1 < left2){
                l = m+1;
            }
        }
        return -1;
    }
};
