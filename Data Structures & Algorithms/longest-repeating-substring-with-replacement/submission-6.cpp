class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> count;
        int l = 0, r = 0;
        int maxLength = 0, maxCount = 0;

        while(r<s.length()){
            count[s[r]]++;
            maxCount = max(maxCount, count[s[r]]);

            if((r - l + 1) - maxCount > k){
                count[s[l]]--;
                l++;
            }

            maxLength = max(maxLength, (r - l + 1));
            r++;

        }
        return maxLength;
    }
};
