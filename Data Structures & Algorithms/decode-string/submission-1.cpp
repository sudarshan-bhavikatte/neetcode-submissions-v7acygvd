class Solution {
private:
    string helper(int& i, string& s) {
        string res = "";

        while (i < s.size() && s[i] != ']') {

            if (isalpha(s[i])) {
                res += s[i];
                i++;
            }

            else if (isdigit(s[i])) {
                int n = 0;

                while (isdigit(s[i])) {
                    n = n * 10 + (s[i] - '0');
                    i++;
                }
                i++;

                string cur = helper(i, s);
                i++;

                while (n--) {
                    res += cur;
                }
            }
        }

        return res;
    }

public:
    string decodeString(string s) {
        int i = 0;
        return helper(i, s);
    }
};