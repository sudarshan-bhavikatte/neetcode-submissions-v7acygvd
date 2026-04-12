class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int, int> str1;

        for(char c : s){
           str1[c - 'a']++; 
        }

        for(char c : t){
            str1[c - 'a']--;
        }

        for(auto it = str1.begin(); it != str1.end(); it++){
            if(it->second != 0) return false;
        }

        return true;
    }
};
