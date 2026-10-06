class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;

        set<char> set;
        int l = 0;
        for(int r = 0; r < s.size(); r++){
            while(set.count(s[r])){
                set.erase(s[l]);
                l++;
            }
            set.insert(s[r]);
            res = max(res, (int)set.size());
        }

        return res;
    }
};
