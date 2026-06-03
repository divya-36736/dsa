class Solution {
public:
    static bool comp(vector<int>a, vector<int>b){
        return a[1] < b[1];
    }

    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        sort(courses.begin(), courses.end(), comp);
        priority_queue<int>pq;

        int currtime = 0;
        for(auto course: courses){
            int duration = course[0];
            int deadline = course[1];

            currtime += duration;
            pq.push(duration);

            if(currtime > deadline){
                currtime -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};