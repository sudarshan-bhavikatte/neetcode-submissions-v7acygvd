class Solution {
public:
    string minWindow(string s, string t) {
        int resLen = INT_MAX;

        unordered_map<char, int> count_t;

        for(char c : t)count_t[c]++;

        int l = 0;
        int r = 0;

        int have = 0;
        int need = count_t.size();
        int start = INT_MAX;
        unordered_map<int, int> window;
        while(r < s.size()){
            char c = s[r];
            window[c]++;

            if(count_t.count(c) && window[c] == count_t[c])have++;

            while(have == need){

                if(r - l + 1 < resLen){
                    start = l;
                    resLen = r - l + 1;
                }
                window[s[l]]--;

                if(count_t[s[l]] && window[s[l]] < count_t[s[l]]){
                    have--;
                }
                l++;
            }
            r++;
        }

        return resLen == INT_MAX ? "" : s.substr(start, resLen);
    }
};
