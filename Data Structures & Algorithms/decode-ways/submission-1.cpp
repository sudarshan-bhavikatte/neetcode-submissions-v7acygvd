class Solution {
private:
    unordered_map<int, int>hash;
    int dfs(int i, string& s){
        if(hash.find(i) != hash.end())return hash[i];

        if(i == s.size())return 1;
        if(s[i] == '0')return 0;

        int res = dfs(i + 1, s);
        if(
            i < s.size() - 1 &&
            (s[i] == '1') ||
            (s[i] == '2' && s[i + 1] < '7')
        ){
            res += dfs(i + 2, s);
        }
        hash[i] = res;
        return res;
    }
public:
    int numDecodings(string s) {
        hash[s.size()] = 1;
        return dfs(0, s);
    }
};
