/**
 *  Search Insert Position
 *  Given a sorted array and a target value, return the index if the target is found. 
 *  If not, return the index where it would be if it were inserted in order.
 */

class Solution1 {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        int size = nums.size();
        for(; i != nums.size(); ++i) {
            if(nums[i] < target) 
                continue;
            else
                return i;
        }
        
        if(i == nums.size())
            return nums.size();
    }
};

class Solution2 {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        while(lo < hi) {
            int mid = lo +(hi-lo)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                hi = mid;
            else
                lo = mid+1;
        }
        
        return (nums[lo] < target)? lo+1:lo;
    }
};