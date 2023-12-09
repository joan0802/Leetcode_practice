class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double sorted[2005];
        int l1 = nums1.size();
        int l2 = nums2.size();
        int i = 0, j = 0, k = 0;
        while(i < l1 && j < l2) {
            if(nums1[i] < nums2[j])
                sorted[k++] = nums1[i++];
            else
                sorted[k++] = nums2[j++];
        }
        while(i < l1)
            sorted[k++] = nums1[i++];
        while(j < l2)
            sorted[k++] = nums2[j++];
        if(k % 2 == 0) 
            return (sorted[(k-1)/2] + sorted[(k-1)/2+1]) / 2;
        else
            return sorted[k/2];
    }
};