#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // int n;
    // vector<int> nums;
    // int bestSum, bestParts;

    // void dfs(int idx, int currSum, int parts, int currAnd) {
    //     if (idx == n) {
    //         currSum += currAnd; // add last subarray
    //         if (currSum < bestSum) {
    //             bestSum = currSum;
    //             bestParts = parts;
    //         } else if (currSum == bestSum) {
    //             bestParts = max(bestPart s, parts);
    //         }
    //         return;
    //     }

    //     // option 1: extend current subarray
    //     dfs(idx + 1, currSum, parts, currAnd & nums[idx]);

    //     // option 2: cut here and start new subarray
    //     dfs(idx + 1, currSum + currAnd, parts + 1, nums[idx]);
    // }

    int maxSubarrays(vector<int>& nums) {
    //     nums = arr;
    //     n = arr.size();
    //     bestSum = INT_MAX;
    //     bestParts = 1;

    //     dfs(1, 0, 1, nums[0]);
    //     return bestParts;


         int G = nums[0];
        for (int x : nums) G &= x;

        if (G != 0) return 1;              // must be a single subarray

        int runningAnd = ~0;               // all 1s
        int count = 0;
        for (int x : nums) {
            runningAnd &= x;
            if (runningAnd == 0) {         // make a cut when AND hits 0
                count++;
                runningAnd = ~0;
            }
        }
        return count;
    }
};
