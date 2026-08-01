class Solution {

    string gen_key(string str){
        vector<int> count(26, 0);

        for(char c : str){
            count[c - 'a']++;
        }

        string key = "";

        for(int c : count){
            key += to_string(c);
            key += "#";
        }

        return key;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for(string str : strs){
            string key = gen_key(str);

            map[key].push_back(str);
        }
        vector<vector<string>> res;

        for(auto it = map.begin(); it != map.end(); it++){
            res.push_back(it->second);
        }
        return res;
    }
};
