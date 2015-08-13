/**
 *  Plus One
 *  将代表整数数组加1，输出整数，999+1 = 1000
 */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i;
        for(i = digits.size()-1; i >= 0; i--) {
            if(digits[i] < 9) {
                ++digits[i];
                return digits;
            }
            
            digits[i] = 0;
        }
        
        if(i < 0) /*全是9*/
            digits.insert(digits.begin(), 1);
        
        
        return digits;
    }
};