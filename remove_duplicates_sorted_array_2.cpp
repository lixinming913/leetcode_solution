/*
 *  Remove Duplicates from Sorted Array II 
 *  Follow up for "Remove Duplicates":
 *  What if duplicates are allowed at most twice?
 */


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(!len) 
            return len;
            
        int count = 1, flag = 0;
        for(int i = 1; i < len; i++) {
            if(nums[i] == nums[i - 1]) {
                count++;
            } else 
                count = 1;
            if(count < 3) 
                nums[++flag] = nums[i];
        }
        
        return flag + 1;
    }
};