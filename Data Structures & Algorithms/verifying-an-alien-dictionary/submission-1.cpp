class Solution {
    unordered_map<char, int> hash;
    bool helper(string word1, string word2){
        int i = 0;
        int j = 0;

        while(i < word1.size() && j < word2.size() && hash[word1[i]] == hash[word2[j]]){
            i++;
            j++;
        }

        if(i < word1.size() && j < word2.size()){
            if(hash[word1[i]] < hash[word2[j]]){
                return true;
            }
            else {
                return false;
            }
        } 
        return word1.size() < word2.size();
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        for(int i = 0; i < order.size(); i++) hash[order[i]] = i;

        for(int i = 1; i < words.size(); i++){
            if(!helper(words[i - 1], words[i])) return false;
        }

        return true;
    }
};