/*
 *  Summary Ranges
 *  Given a sorted integer array without duplicates, return the summary of its ranges.
 *  For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 */


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> str;
        if(nums.empty())
            return str;
        
        string flag = "->";
        string temp;
        
        for(int i = 0; i < nums.size();) {
            
            int j = i + 1;
            for(; j < nums.size();) {
                
                if((j - i) != (nums[j] - nums[i])) {
                    if((j-i) == 1) {
                        temp = to_string(nums[i]);
                        str.push_back(temp);
                    } else {
                        string s1 = to_string(nums[i]);
                        string s2 = to_string(nums[j-1]);
                        temp = s1 + flag + s2;
                        str.push_back(temp);
                    }
                    break;
                }
                
                ++j;
            }
            if(j == nums.size()) {
                if((j-i) == 1)
                    str.push_back(to_string(nums[i]));
                else
                {
                    string s1 = to_string(nums[i]);
                    string s2 = to_string(nums[j-1]);
                    temp = s1 + flag + s2;
                    str.push_back(temp);
                }
            }
                
            i = j;
        }
        
        return str;
        
    }
};