class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int res = 0;
        unordered_set<char> S;
        
        for(int r = 0; r < s.size(); r++){
            while(S.find(s[r]) != S.end()){
                S.erase(s[l]);
                l++;
            }
            S.insert(s[r]);
            res = max(res, r - l + 1);
        }
        return res;
    }
};
