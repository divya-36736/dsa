class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int n = s.size();
        // int maxi = INT_MIN;
        // if(n == 0) return 0;
        // for(int i = 0; i<n; i++){
        //     unordered_set<int>set;
        //     for(int j = i; j<n; j++){
        //         if (set.find(s[j]) != set.end())
        //         {
        //             maxi = max(maxi, j - i);
        //             break;
        //         }
        //     set.insert(s[j]);
        //     maxi = max(maxi, j - i + 1);
        //     }
        // }
        // return maxi;

        //optimal 1;
        int n = s.size();
        int maxi = 0; // Initialize to 0
        unordered_set<char> set; // Use char
        int l = 0;
        
        if (n == 0) return 0; // Handle empty string
        
        for (int r = 0; r < n; r++) {
            while (set.find(s[r]) != set.end()) { // Fixed condition
                set.erase(s[l]);
                l++;
            }
            set.insert(s[r]);
            maxi = max(maxi, r - l + 1);
        }
        
        return maxi;
    }
};