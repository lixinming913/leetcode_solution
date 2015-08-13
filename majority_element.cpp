/*   
 *  Majority Element
 *  Given an array of size n, find the majority element. 
 *  The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 */
 
 
 /*36ms*/
class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>::iterator mid = nums.begin() + nums.size()/2;
        return *mid;
    }
};


/*16ms*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result = nums[0];
        int times  = 1;
        for(int i = 1; i < nums.size(); ++i) {
            if(times == 0) {
                result = nums[i];
                times  = 1;
            } else if(nums[i] == result) {
                times++;
            } else
                times--;
        }
        
        return result;
    }
};