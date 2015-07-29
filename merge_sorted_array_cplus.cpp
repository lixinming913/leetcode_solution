/**
 *  Merge Sorted Array 
 *  nums1's size is greater or equal to m+n 
 *  using vector's feather to sort inserted data
 */


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = m, j = 0; i < m+n ; ++i,++j)
            nums1[i] = nums2[j];
        sort(nums1.begin(), nums1.end());
    }
};