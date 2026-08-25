class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int m = cost.size();
        int totgas = 0;
        int totcost = 0;
       for(int i = 0; i<n; i++){
        totgas += gas[i];
       }
       for(int i = 0; i<n; i++){
        totcost += cost[i];
       }
       if(totgas < totcost) return -1;
       int currgas = 0;
       int st = 0;
       for(int i = 0; i<n; i++){
        currgas += gas[i] - cost[i];
        if(currgas < 0){
            st = i+1;
            currgas = 0;
        }
       }
       return st;
    }
};