/**
 *  Remove Element
 *  Given an array and a value,
 *  remove all instances of that value in place and return the new length.
 *  The order of elements can be changed. 
 *  It doesn't matter what you leave beyond the new length.
 */


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty())
            return 0;
        
        int end = nums.size() - 1;
        for(int i = 0; i <= end; ++i) {
            if(nums[i] == val) {
                while(i < end && nums[end] == nums[i]) {
                    end--;
                }
                
                if(i < end)
                    swap(nums[i], nums[end]);
                
                end--;
            }
        }
        
        return end+1;
    }
};