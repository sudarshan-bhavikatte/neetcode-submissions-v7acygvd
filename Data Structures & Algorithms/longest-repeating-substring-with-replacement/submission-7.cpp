class Solution {
public:
    int characterReplacement(string s, int k) {

        vector<int> freq(26, 0);

        int l = 0;
        int maxFreq = 0;
        int res = 0;

        for(int r = 0; r < s.size(); r++) {

            freq[s[r] - 'A']++;

            maxFreq = max(maxFreq, freq[s[r] - 'A']);

            while((r - l + 1) - maxFreq > k) {
                freq[s[l] - 'A']--;
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};