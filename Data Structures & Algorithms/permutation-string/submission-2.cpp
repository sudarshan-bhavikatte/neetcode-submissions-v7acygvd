class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        unordered_map<char, int> count_s1;
        for (char c : s1)
            count_s1[c]++;

        int have = 0;
        int need = count_s1.size();

        unordered_map<char, int> count_s2;

        int l = 0;

        for (int r = 0; r < s2.size(); r++) {
            char c = s2[r];
            count_s2[c]++;

            if (count_s1.count(c) && count_s2[c] == count_s1[c])
                have++;

            // Keep window size equal to s1.size()
            while (r - l + 1 > s1.size()) {
                char left = s2[l];

                if (count_s1.count(left) &&
                    count_s2[left] == count_s1[left])
                    have--;

                count_s2[left]--;
                l++;
            }

            if (have == need)
                return true;
        }

        return false;
    }
};