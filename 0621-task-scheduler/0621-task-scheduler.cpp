class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int, int>freq;
        for(auto &task:tasks){
            freq[task]++;
        }

        priority_queue<int>maxh;
        for(auto &it:freq){
            maxh.push(it.second);
        }

        int time = 0;

        while(!maxh.empty()){
            vector<int>temp;
            int i = 0;
            int cycle = n+1;

            while(i<cycle && !maxh.empty()){
                int cnt = maxh.top();
                maxh.pop();

                cnt--;

                if(cnt > 0){
                    temp.push_back(cnt);
                }

                time++;
                i++;
            }

            for(int val:temp){
                maxh.push(val);
            }

            if(maxh.empty()) break;

            time += (cycle-i);
        }
        return time;
    }
};