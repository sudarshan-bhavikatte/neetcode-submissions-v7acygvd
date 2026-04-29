/*

1. given n cars with pos, and speed moving in same direction and same dest.
2. position[i] is the position of the ith car (in miles),
         => distance from target = target - pos[i]
    speed[i] is the speed of the ith car (in miles per hour)
    The destination is at position target miles.

3. No overtaking, 
    It can only catch up to another car and 
    then drive at the same speed as the car ahead of it
4. car fleet : cars running in same speed in a line
5. find number of car fleets reach the dest

----

1. we can use time taken to find which car aporoachs other cars
2. we can use a stack to stack up the cars while the time taken by the car on top is
    lesser or equal then the car to be added
3. if its greater we empty the stack and count it as a car fleet
4. pos arr is not sorted need to sort it in desc order and create hash for speeds

*/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int res = 0;
        unordered_map<int, int> hash;

        for(int i = 0; i < position.size(); i++)hash[position[i]] = speed[i];
        sort(position.begin(), position.end(), greater<int>());

        stack<float> s;

        for(int i = 0; i < position.size(); i++){
            float time = (float)(target - position[i]) / (float)hash[position[i]];
            cout << time << endl;
            if(s.empty()){
                s.push(time);
            }
            else if(s.top() >= time){
                s.push(s.top());
            }
            else {
                res++;
                while (!s.empty()) {
                    s.pop();
                    }
                s.push(time);
            }
        }
        if(!s.empty()) res++;
        return res;

        
    }
};
