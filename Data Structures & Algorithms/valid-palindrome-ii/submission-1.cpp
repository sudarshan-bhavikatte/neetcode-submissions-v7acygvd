class Solution {
   public:
    bool checkPal(string s) {
        int l = 0;
        int r = s.size() - 1;

        while (l <= r) {
            while (l < r && !isalnum(s[l])) l++;
            while (l < r && !isalnum(s[r])) r--;

            if (tolower(s[l]) == tolower(s[r])) {
                l++;
                r--;
            } else {
                return false;
            }
        }

        return true;
    }

    bool validPalindrome(string s) {
        int n = s.size();

        int l = 0;
        int r = s.size() - 1;

        while (l <= r) {
            while (l < r && !isalnum(s[l])) l++;
            while (l < r && !isalnum(s[r])) r--;

            if (tolower(s[l]) == tolower(s[r])) {
                l++;
                r--;
            } else {
                cout << s.substr(0, l - 1) + s.substr(l, n - l) << " " << s.substr(0, r - 1) + s.substr(r, n - r);
                return checkPal(s.substr(0, l) + s.substr(l + 1, n - l)) ||
                       checkPal(s.substr(0, r) + s.substr(r + 1, n - r));
            }
        }

        return true;
    }
};