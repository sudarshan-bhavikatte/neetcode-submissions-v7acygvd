class Solution {
public:
    bool isPalindrome(string s) {
        string newStr = "";

        for (char c : s){
            if(c >= 'a' && c <= 'z' || c >= '0' && c <='9'){
                newStr += c;
            }
            else if(c >= 'A' && c <= 'Z'){
                newStr += (char)(c + 32);
            }
        }
        string rStr = newStr;
        int i=0;
        int j = newStr.size() - 1;
        while (i<=j){
            rStr[i] = newStr[j];
            rStr[j] = newStr[i];
            i++;
            j--;
        }
        return (newStr == rStr);
    }
};
