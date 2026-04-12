class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);

        for(char task : tasks){
            count[task - 'A']++;
        }

        priority_queue<int> pq;

        for(int c : count){
            if(c > 0) pq.push(c);
        }

        queue<pair<int,int>> q;
        int time = 0;

        while(!pq.empty() || !q.empty()){
            time++;

            
            if(!pq.empty()){
                int cnt = pq.top() - 1;pq.pop();
                if(cnt > 0){
                    q.push({cnt, time + n});
                }
            } else {
                time = q.front().second;
            }

            if(!q.empty() && time == q.front().second){
                    pq.push(q.front().first);
                    q.pop();
                
            }
        }

        return time;
    }
};
