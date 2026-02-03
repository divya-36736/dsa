class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 1;
        while(i<n && nums[i]>nums[i-1]){ //strictly increasing
            i++;
        }
        if(i == 1 || i == n) return false;
        while(i<n && nums[i]<nums[i-1]){ //strictly decreasing
            i++;
        }
        if(i == n) return false;

        while(i<n && nums[i] > nums[i-1]){ //strictly increasing
            i++; 
        }
        return i == n;
    }
};