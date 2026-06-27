class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int> &a, vector<int> &b) {
        return a[1] > b[1]; 
        });
        int i = 0;
        int t = truckSize;
        int ans = 0;
        while(i<n && t>0){
            if(boxTypes[i][0]<=t){
                t = t-boxTypes[i][0];
                ans += (boxTypes[i][0] * boxTypes[i][1]);
            }else{
                ans += (t * boxTypes[i][1]);
                t = 0;
            }
            i++;
        }
        return ans;
    }
};