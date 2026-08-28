class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<pair<int,pair<int,int>>>arr;
        vector<vector<int>>ans;
        
        for(int i = 0; i<n; i++){
            int x = points[i][0];
            int y = points[i][1];
            int dist = x*x + y*y;
            arr.push_back({dist, {x, y}});
        }

        sort(arr.begin(), arr.end());
        for(int i = 0; i<k; i++){
            ans.push_back({arr[i].second.first, arr[i].second.second});
        }
        return ans;
    }
};