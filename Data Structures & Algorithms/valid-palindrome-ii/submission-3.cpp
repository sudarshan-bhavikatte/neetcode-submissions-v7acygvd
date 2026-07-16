class Solution {
public:
    bool solution(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0,j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return solution(s,i+1,j)||solution(s,i,j-1);
            }
            i++;j--;
        }
        return true;
    }
};