class Solution {
private:
    string create_key(string str){
        vector<int> count(26, 0);

        for(char c : str){
            count[c - 'a']++;
        }
        string key = to_string(count[0]);
        
        for(int i = 1; i < 26; i++){
            key += ",";
            key += count[i];
        }

        return key;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> hash;

        for(string str : strs){
            string key = create_key(str);

            hash[key].push_back(str);
        }

        for(auto it = hash.begin(); it != hash.end(); it++){
            res.push_back(it->second);
        }
        return res;
    }
};
