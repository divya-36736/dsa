class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        //answer is unique numbers in array
        unordered_set<int> s;
        for(int x : nums){
            if(x>0) s.insert(x);
        }
        return s.size();
    }
};