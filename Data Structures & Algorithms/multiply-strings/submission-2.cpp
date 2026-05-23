class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        vector<int> res(num1.size() + num2.size(), 0);


        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for(int i = 0; i < num1.size(); i++){
            for(int j = 0; j < num2.size(); j++){
                int a = num1[i] - '0'; 
                int b = num2[j] - '0';

                int digit = (a * b);

                res[i + j] += digit ;
                res[i + j + 1] += res[i + j] / 10;
                res[i + j] %= 10;
            }
        }

        stringstream res_str;
        int i = res.size() - 1;

        while(i >= 0 && res[i] == 0)i--;

        while(i >= 0){
            res_str << res[i];
            i--;
        }

        return res_str.str();
    }
};
