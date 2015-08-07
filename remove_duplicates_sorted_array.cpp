/*
 *  Remove Duplicates from Sorted Array 
 *  Given input array nums = [1,1,2],
 *  Your function should return length = 2, 
 *  with the first two elements of nums being 1 and 2 respectively. 
 */
 
class Solution1 {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
            
        sort(nums.begin(), nums.end());
        vector<int>::iterator index = unique(nums.begin(), nums.end());
        
        int i = 0;
        for(vector<int>::iterator iter = nums.begin(); iter != index; ++iter)
            ++i;
            
        return i;
    }
};

class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
    
        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1])
                count++;
            else if (count != 0)
                nums[i - count] = nums[i];
        }
        nums[n - 1 - count] = nums[n - 1];
        
        return n - count;
    }
};
