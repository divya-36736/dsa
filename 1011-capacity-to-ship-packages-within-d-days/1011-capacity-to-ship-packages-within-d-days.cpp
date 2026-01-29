class Solution {
public:
    int countDay(vector<int>&weights, int cap){
        int day = 1;
        int weight = 0;
        for(int w:weights){
            
            if(weight + w > cap){
                day++;
                weight = w; // start new day with current weight
            }
            else{
                weight += w;
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int maxCap = 0;
        for(int w:weights){
            maxCap += w;
        }
        //mincap joh maximum wale ko toh le hi jae
        
        int minCap = *max_element(weights.begin(), weights.end());

        int res = 0;
        int st = minCap;
        int end = maxCap;
        while(st<=end){
            int mid = st+(end-st)/2;
            int day = countDay(weights, mid);
            if(day <= days){
                res = mid;
                end = mid-1;
            }
            else{
                st = mid+1;
            }
        }
        return res;
    }
};