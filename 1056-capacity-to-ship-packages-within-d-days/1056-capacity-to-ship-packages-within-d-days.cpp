class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int minCap = 0;
        int maxCap = 0;
        for(int weight: weights){
            minCap = max(minCap, weight);
            maxCap += weight;
        }
        while(minCap < maxCap){
            int mid = minCap + (maxCap - minCap)/2;
            int day = 1;
            int sum = 0;
            for(int weight: weights){
                if(sum + weight > mid){
                    day++;
                    sum = 0;
                }
                sum += weight;
            }
            if(day > days) minCap = mid + 1;
            else maxCap = mid;
        }
        return minCap;
    }
};

// class Solution {
//     public int shipWithinDays(int[] weights, int days) {
//         int max=weights[0];
//         int sum=0;
//         for(int i=0;i<weights.length;i++){
//             if(weights[i]>max) max=weights[i];
//             sum+=weights[i];
//         }
//         int n=weights.length;
//         int min=max;
//         max=sum;
//         while(min<=max){
//             int ans=1;
//             int s=0;
//             int mid=min+(max-min)/2;
//             if(capacity(weights,days,mid)){
//                 max=mid-1;
//             }
//             else{
//                 min=mid+1;
//             }
//             }
//         return min;
        
//     }
//       private boolean capacity(int[] weights, int days, int capacity) {
//         int dayCount = 1, currentWeight = 0;
//         for (int w : weights) {
//             if (currentWeight + w > capacity) {
//                 dayCount++;
//                 currentWeight = 0;
//             }
//             currentWeight += w;
//         }
//         return dayCount <= days;
//     }
// }i