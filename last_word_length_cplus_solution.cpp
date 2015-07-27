/*
 *  Length of Last Word 
 */


class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = s.size() - 1;
        int len_word = 0;
        
        for(int i = end; i >= 0; --i) {
            if(s[i] == ' ' && len_word > 0)
                return len_word;
            
            if(s[i] == ' ')
                continue;
                
            
            len_word++;
        }
        
        return len_word;
    }
};