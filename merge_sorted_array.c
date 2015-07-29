/**
 *  Merge Sorted Array
 *  You may assume that nums1 has enough space 
 *  (size that is greater or equal to m + n) to hold additional elements from nums2. 
 */


void merge(int* nums1, int m, int* nums2, int n) {
    int i = m-1, j =n-1;
    int len = m+n-1;
    
    while(i >= 0 && j >= 0) {
        if(nums1[i] <= nums2[j])
            nums1[len--] = nums2[j--];
        else
            nums1[len--] = nums1[i--];
    }
    
    while(i >= 0)
        nums1[len--] = nums1[i--];
    while(j >= 0)
        nums1[len--] = nums2[j--];
}