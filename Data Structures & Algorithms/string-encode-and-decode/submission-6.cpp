class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString;
        for(string s : strs){
            int length = s.size();
            encodedString += to_string(length) + "#" + s;
        }
        std::cout << encodedString << std::endl;
        return encodedString;
    }

    vector<string> decode(string s) {
        vector<string> decodedVector;
        size_t size = s.size();
        size_t i = 0;
        while (i < size){
            string length;
            while (s[i] != '#'){
                length += s[i];
                i++;
            }
            int l = std::stoi(length); 
            i++;
            string word;
            for (int j=0;j<l;j++){
                word += s[i];
                i++;
            }
            std::cout << word << " ";
            decodedVector.push_back(word);
        }
        return decodedVector;
    }
};
