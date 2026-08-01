class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;

        unordered_set<char> set;

        int i = 0;
        for(int j = 0; j < s.size(); j++){
            while(set.count(s[j])){
                set.erase(s[i]); i++;
            }
            set.insert(s[j]);
            res = max((j - i + 1), res);
        }

        return res;
    }
};
