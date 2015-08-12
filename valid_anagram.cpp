/**
 *  Valid Anagram 
 *  Given two strings s and t, write a function to determine if t is an anagram of s.
 *  For example,s = "anagram", t = "nagaram", return true.s = "rat", t = "car", return false.
 */

 
class Solution1{
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s==t;
    }
};


class Solution2{
public:
    bool isAnagram(string s, string t) {
        int ans_a = 1, ans_b = 1;
        int ans_c = 0, ans_d = 0;
        
        for(int i = 0; i < s.length(); ++i) {
            ans_a *= s[i];
            ans_c += s[i];
        }
        
        for(int i = 0; i < t.length(); ++i) {
            ans_b *= t[i];
            ans_d += t[i];
        }

        return ans_a == ans_b && ans_c == ans_d;
    }
};