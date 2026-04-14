/*
    1. return max(len of substring) where :
        - no duplicate characters

    sol:
        1. use set to check if duplicate exist
        2. if a duplicate is found we have to shift the L pointer
        3. we will need the index of the character of which the duplicate is found
        4. we can use unordered_map
    
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        if (s.length() == 1) return 1;
        int L = 0;

        unordered_map<char, int> hash;

        for(int R = 0; R < s.length(); R++){
            auto it = hash.find(s[R]);
        if (it != hash.end() && it->second >= L) {
            L = it->second + 1;
        }

            hash[s[R]] = R;
            res = max(res, R - L + 1);
        }
        return res;
    }
};
