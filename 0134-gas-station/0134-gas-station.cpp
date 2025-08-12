class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int g = gas.size();
        int c = cost.size();
        //total gas
        int totgas = 0;
        int totcost = 0;
        // for(int val:gas){
        //     totgas += val;
        // }
        // //total cost
        // for(int val: cost){
        //     totcost += val;
        // }
        // //if this fail
        // if(totgas < totcost){
        //     return -1;
        // } 
        //in above 2 different loops use krene ki bjay 
        //hum sara ek hi loop me kr dakte hai 

        int st = 0;
        int currgas = 0;
        for(int i = 0; i<g; i++){
            totgas+=gas[i];
            totcost += cost[i];
            currgas += (gas[i]-cost[i]);
            if(currgas<0){
                st = i+1;
                currgas = 0;
            }
        }

        return totgas < totcost? -1:st;


        // int st = 0;
        // int currgas = 0;
        // for(int i = 0; i<g; i++){
        //     currgas += (gas[i]-cost[i]);
        //     if(currgas<0){
        //         st = i+1;
        //         currgas = 0;
        //     }
        // }

        // return st;
    }
};