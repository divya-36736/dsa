class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int, int>freq;
        for(char c: tasks){
            freq[c]++;
        }

        int cycle = n+1;
        int time = 0;
        priority_queue<int>pq;
        for(auto &it: freq){
            pq.push(it.second);
        }

        while(!pq.empty()){
            vector<int>temp;
            int i = 0;
            

            while(i<cycle && !pq.empty()){
                int cnt  = pq.top();
                pq.pop();

                cnt--;
                if(cnt>0){
                    temp.push_back(cnt);
                }
                time++;
                i++;
            }

            for(auto &it:temp){
                pq.push(it);
            }
            if(pq.empty()){
                break;
            }

            time += (cycle-i);
        }
        return time;
    }
};