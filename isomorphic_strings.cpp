/**
 *  Isomorphic Strings 
 *  Given two strings s and t, determine if they are isomorphic.
 *  Two strings are isomorphic if the characters in s can be replaced to get t.
 *  For example, Given "egg", "add", return true.Given "foo", "bar", return false.
 */
 

class Solution1 {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())
            return false;
        map<char, char> my_map;
        for(int i = 0; i < s.size(); ++i) {
            if(my_map.find(s[i]) == my_map.end())
                my_map[s[i]] = t[i];
            else if(my_map[s[i]] != t[i])
                return false;
        }
        
        my_map.clear();
        for(int i = 0; i < s.size(); ++i) {
            if(my_map.find(t[i]) == my_map.end())
                my_map[t[i]] = s[i];
            else if(my_map[t[i]] != s[i])
                return false;
        }
        
        return true;
    }
};


class Solution2 {
public:
    bool isIsomorphic(string s, string t) {        
        char ss[256] = {0};
        char tt[256] = {0};
        
        for(int i = 0; i < s.size(); ++i) {
            /*hash map: s->t*/
            if(ss[s[i]] != 0) {
                if(ss[s[i]] != t[i])
                    return false;       
            } else {
                ss[s[i]] = t[i];
            }
            /*hash map: t->s*/
            if(tt[t[i]] != 0) {
                if(tt[t[i]] != s[i]) 
                    return false;
            } else {
                tt[t[i]] = s[i];
            }
        }
        
        return true;
        
    }
};