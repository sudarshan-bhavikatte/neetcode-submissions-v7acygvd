class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;

        unordered_set<char> set(s.begin(), s.end());

        for(char c : set){
            int i = 0;
            int count = 0;
            for(int j = 0; j < s.size(); j++){
                if(s[j] == c)count++;

                while((j - i + 1) - count > k ){
                    if(s[i] == c)count--;
                    i++;
                }

                res = max(res, (j - i + 1));
            }
        }

        return res;
    }
};
