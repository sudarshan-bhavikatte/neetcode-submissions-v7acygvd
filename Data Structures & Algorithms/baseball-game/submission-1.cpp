class Solution {
private:
public:
    int calPoints(vector<string>& operations) {
        vector<int> record;

        for(int i=0; i < operations.size(); i++){
           
            if(operations[i] == "+"){
                int a = record[record.size() - 1];
                int b = record[record.size() - 2];
                record.push_back(a + b);
            }
            else if(operations[i] == "D"){
                int a = record[record.size() - 1];
                record.push_back(a * 2);
            }
            else if(operations[i] == "C"){
                record.pop_back();
            }
            else {
                record.push_back(stoi(operations[i]));
            }
            
        }   
        int sum = 0;

        for(int r : record){
            sum += r;
        }

        return sum;
    }
};