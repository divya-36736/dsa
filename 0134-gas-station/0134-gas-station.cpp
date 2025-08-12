class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int g = gas.size();
        int c = cost.size();
        //total gas
        int totgas = 0;
        int totcost = 0;
        for(int val:gas){
            totgas += val;
        }
        //total cost
        for(int val: cost){
            totcost += val;
        }
        //if this fail
        if(totgas < totcost){
            return -1;
        }
        int st = 0;
        int currgas = 0;
        for(int i = 0; i<g; i++){
            currgas += (gas[i]-cost[i]);
            if(currgas<0){
                st = i+1;
                currgas = 0;
            }
        }

        return st;
    }
};