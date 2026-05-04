class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        vector<vector<string>> res;
        for(string s : strs){
            vector<int> v(26, 0);

            for(int c : s){
                v[c - 'a']++;
            }
            string key = "";
            for(int i = 0; i < 26; i++){
                key += to_string(v[i]) + "#";
            }
            hash[key].push_back(s);
        }

        for(auto it = hash.begin(); it != hash.end(); it++){
            res.push_back(it->second);
        }

        return res;
    }
};
