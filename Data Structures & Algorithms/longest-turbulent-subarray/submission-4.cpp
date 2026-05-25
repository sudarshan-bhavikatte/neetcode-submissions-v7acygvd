class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int res = 1;
        string prev = "";
        int i = 0;
        int j = 1;
        while(j < arr.size()){
            if(arr[j - 1] < arr[j] && prev != "<"){
                res = max(res,(j - i + 1));
                prev = "<";
                j++;
            }
            else if(arr[j - 1] > arr[j] && prev != ">"){
                res = max(res,(j - i + 1));
                prev = ">";
                j++;
            }
            else {
                if(arr[j - 1] == arr[j]){
                    j++;
                }
                i = j - 1;
                prev = "";
            }
        }

        return res;
    }
};