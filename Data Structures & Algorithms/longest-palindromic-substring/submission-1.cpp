class Solution {
public:
    string longestPalindrome(string s) {
        int len = 0;

        string res;
        for(int i = 0; i < s.size(); i++){
            int l = i; int r = i;

            while(l >= 0 && r < s.size() && s[l] == s[r]){
                if(r - l + 1 > len){
                    len = (r - l + 1);
                    res = s.substr(l, len);
                }
                l--;
                r++;
            }

            l = i; r = i + 1;

            while(l >= 0 && r < s.size() && s[l] == s[r]){
                if(r - l + 1 > len){
                    len = (r - l + 1);
                    res = s.substr(l, len);
                }
                l--;
                r++;
            }
        }

        return res;
    }
};
