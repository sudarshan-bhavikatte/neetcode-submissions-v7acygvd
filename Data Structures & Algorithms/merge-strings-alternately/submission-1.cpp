class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";

        int n1 = word1.size();
        int n2 = word2.size();

        int p1 = 0;
        int p2 = 0;

        while(p1 < n1 && p2 < n2){
            res += word1[p1];
            res += word2[p2];
            p1++;
            p2++;
        }
        if(p1 < n1){
            res += word1.substr(p1);
        }
        if(p2 < n2){
            res += word2.substr(p2);
        }

        return res;
    }
};