/**
 *  Group Anagrams 
 *  For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
 *  [  ["ate", "eat","tea"],  ["nat","tan"],  ["bat"]   ]
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s==t;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        vector<string> ana;
        vector<int> pos;
        if(strs.empty())
            return {};
            
        for(int i = 0 ; i < strs.size(); i++) {
            ana.push_back(strs[i]);
            for(int j = i+1; j < strs.size(); j++) {
                if(isAnagram(strs[i], strs[j])) {
                    ana.push_back(strs[j]);
                    pos.push_back(j);
                }
            }
            res.push_back(ana);
            for(int k = 0; k < pos.size(); k++)
                strs[pos[k]] = ' ';
            ana.clear();
        }
        
        return res;
    }
};