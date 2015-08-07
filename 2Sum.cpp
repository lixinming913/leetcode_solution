/*
 *  2Sum
 *  Input: numbers={2, 7, 11, 15}, target=9
 *  Output: index1=1, index2=2
 */


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.size() < 2)
            return {};
            
        vector<int> numsCopy(nums.begin(), nums.end());
        sort(numsCopy.begin(), numsCopy.end()); 

        int i = 0;
        int j = numsCopy.size()-1;

        while (i < j)
        {
            int sum = numsCopy[i] + numsCopy[j];
            if (sum < target)
                i++;
            else if (sum > target)
                j--;
            else
            {
                break;
            }
        }

        return GetIndexOfAddends(nums, numsCopy[i], numsCopy[j]);
    }

private:
    vector<int> GetIndexOfAddends(const vector<int>& nums, int addend1, int addend2)
    {
        vector<int> result;

        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i] == addend1 || nums[i] == addend2)
            {
                result.push_back(i+1);
            }
        }

        return result;
    }

};