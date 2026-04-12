class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        if(n2 < n1)return false;

        unordered_map<char,int> hash1;
        for(char c : s1){
            hash1[c]++;
        }
        int l_hash1 = hash1.size();

        for(int i=0;i<n2;i++){
            unordered_map<char,int> hash2;
            int count = 0;
            for(int j=i;j<n2;j++){
                char c = s2[j];
                hash2[c]++;

                if(hash2[c] > hash1[c])break;
                
                if(hash1[c] == hash2[c]){
                    count++;
                }
                if(count == l_hash1)return true;
            }
        }
        return false;
    }
};
