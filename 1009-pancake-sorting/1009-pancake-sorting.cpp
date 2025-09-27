class Solution {
public:
    
    vector<int> pancakeSort(vector<int>& arr) {
        // greedy approach
        vector<int> res;
        int n = arr.size();

        for (int size = n; size > 1; size--) {
            // Find index of the largest element in arr[0..size-1]
            int maxIndex =
            max_element(arr.begin(), arr.begin() + size) - arr.begin();

            if (maxIndex != size - 1) {
                //Flip to bring max to front
                if (maxIndex != 0) {
                    res.push_back(maxIndex + 1);
                    reverse(arr.begin(), arr.begin() + maxIndex + 1);
                }
                //Flip to move max to its correct position
                res.push_back(size);
                reverse(arr.begin(), arr.begin() + size);
            }
        }

        return res;
    }
};