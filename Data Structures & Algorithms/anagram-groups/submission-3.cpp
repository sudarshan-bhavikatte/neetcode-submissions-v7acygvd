class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        for(string str : strs){
            string key = "";
            vector<int> count(26, 0);
            for(char c : str)count[c - 'a']++;
            for(int c : count){
                key += "#";
                key += to_string(c);
            }
            res[key].push_back(str);
        }
        vector<vector<string>> res_vec;

        for(auto it = res.begin(); it != res.end(); it++){
            res_vec.push_back(it->second);
        }

        return res_vec;
    }
};
