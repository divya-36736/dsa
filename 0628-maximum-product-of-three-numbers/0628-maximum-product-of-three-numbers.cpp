class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        long long firstMax= INT_MIN, secondMax = INT_MIN, thirdMax = INT_MIN;
        long long min1 = INT_MAX;
        long long min2 = INT_MAX;

        for(auto it: nums){
            //update top 3 max
            if(it > firstMax){
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = it;
            }
            else if(it > secondMax){
                thirdMax = secondMax;
                secondMax = it;
            }else if(it > thirdMax){
                thirdMax = it;
            }
            if(it < min1){
                min2 = min1;
                min1 = it;
            }else if(it < min2){
                min2 = it;
            }
        }
        return max(firstMax*secondMax*thirdMax, firstMax*min1*min2);
    }
};