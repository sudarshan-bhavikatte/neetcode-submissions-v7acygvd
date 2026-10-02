class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;

        for(string str : strs){
            string key = str;
            sort(key.begin(), key.end());
            hash[key].push_back(str);
        }

        vector<vector<string>> res;

        for(auto it = hash.begin(); it != hash.end(); it++){
            res.push_back(it->second);
        }

        return res;
    }
};
