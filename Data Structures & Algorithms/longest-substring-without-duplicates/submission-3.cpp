class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int left = 0, right = 0;
        int len = 0;
        unordered_map<char, int> hash;
        
        while (right < s.size()) {
            if (!hash[s[right]]) {
                hash[s[right]]++;
                len++;
                res = max(res, len);  // ✅ move this here
                right++;
            } else {
                hash[s[left]]--;
                len--;
                left++;
            }
        }
        return res;
    }
};
