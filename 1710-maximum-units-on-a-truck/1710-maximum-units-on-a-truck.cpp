class Solution {
public:
    static bool compare(vector<int>&a, vector<int>&b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        int size = truckSize;
        //we do soring to considering the unit/box bcz we need to maximum 
        //units
        sort(boxTypes.begin(), boxTypes.end(), compare);
        int maxunits = 0;
        for(int i = 0; i<n; i++){
            if(size >= boxTypes[i][0]){
                size = size - boxTypes[i][0];
                maxunits += (boxTypes[i][0] * boxTypes[i][1]);
            }
            else if(size < boxTypes[i][0] && size>0){
                maxunits  += size*boxTypes[i][1];
                break;
            }
        }
        return maxunits;
    }
};