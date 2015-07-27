/*
 *  House Robber 
 *  You are a professional robber planning to rob houses along a street.
 *  Each house has a certain amount of money stashed, the only constraint 
 *  stopping you from robbing each of them is that adjacent houses have security
 *  system connected and it will automatically contact the police if two adjacent houses
 *  were broken into on the same 
 */

int rob(int* nums, int numsSize) {
    if(numsSize == 0)
        return 0;
    if(numsSize == 1)
        return (nums[0]>nums[1])?nums[0]:nums[1];
        
    int max_money[numsSize];
    
    max_money[0] = nums[0];
    max_money[1] = (nums[0]>nums[1])?nums[0]:nums[1];
    for(int i = 2; i < numsSize; ++i) {
        int m = max_money[i-2] + nums[i];
        m = (m > max_money[i-1])? m:max_money[i-1];
        max_money[i] = m;
    }
    
    return max_money[numsSize-1];
}