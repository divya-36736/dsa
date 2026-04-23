class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();

        // Storing the index for each value
        unordered_map<int,vector<int>>groups;
        for (int i = 0 ; i < n ; i++){
            groups[nums[i]].push_back(i);
        }
        
        vector<long long >result(n,0);

        // Processing each group seprately 
        for (auto &entry : groups){
            vector<int>&positions = entry.second ;
            int k = positions.size();

            long long totalSum = 0 ;
            for (int pos : positions){
                totalSum += pos ;
            }

            long long prefixSum = 0 ;
            for (int i = 0 ; i < k ; i++){
                int currentPos = positions[i];

                // Left Side 
                // distance from all previous indexes 
                long long left = (long long)currentPos * i - prefixSum ;
                // Right Side 
                // distnace to all future indices 
                long long right = (totalSum - prefixSum - currentPos) - (long long)currentPos * (k - i -1);

                result[currentPos] = left + right ;
                prefixSum += currentPos;
            }
        }
        return result ;
    }
};