class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>>ans;
        int mini = INT_MAX;
        for(int i = 0; i<n-1; i++){
            int diff = arr[i+1] - arr[i];
            mini = min(mini, diff);
        }
        for(int i = 0; i<n-1; i++){
            int diff = arr[i+1]-arr[i];
            if(mini == diff){
                ans.push_back({arr[i], arr[i+1]});
            }
        }
        return ans;
    }
};