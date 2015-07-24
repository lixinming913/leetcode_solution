/**
 *  Contains Duplicate 
 *  Given an array of integers, find if the array contains any duplicates.
 *  Your function should return true if any value appears at least twice in the array, 
 *  and it should return false if every element is distinct.
 */

/* 96ms*/
class Solution1 {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> my_nums;

        vector<int>::iterator iter = nums.begin();
        for(; iter != nums.end(); ++iter)
            ++my_nums[*iter];
           
        if(my_nums.size() != nums.size())
            return true;
        return false;
    }
};

/*52ms*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> my_nums(nums.begin(),nums.end());

           
        if(my_nums.size() != nums.size())
            return true;
        return false;
    }
};

/*40ms*/
class Solution2 {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if((unique(nums.begin(), nums.end())) != nums.end())
            return true;
        return false;
    }
};