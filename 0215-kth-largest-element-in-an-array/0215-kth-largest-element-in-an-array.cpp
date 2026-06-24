class Solution {
public:
    // Function to get a random pivot index
    int randomIdx(int l, int r) {
        int len = r - l + 1;
        return (rand() % len) + l;
    }

    // Partition the array and return the final position of pivot
    int partitionAndReturnIdx(vector<int>& nums, int pivotIdx, int l, int r) {
        int pivot = nums[pivotIdx];

        // Move pivot to the beginning
        swap(nums[l], nums[pivotIdx]);

        int idx = l + 1;

        // Place all elements greater than pivot to the left side
        for (int i = l + 1; i <= r; i++) {
            if (nums[i] > pivot) {
                swap(nums[idx], nums[i]);
                idx++;
            }
        }

        // Place pivot at its correct position
        swap(nums[l], nums[idx - 1]);

        return idx - 1;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        if (k > n) return -1;

        int l = 0;
        int r = n - 1;

        while (true) {
            int pivotIdx = randomIdx(l, r);

            pivotIdx = partitionAndReturnIdx(nums, pivotIdx, l, r);

            if (pivotIdx == k - 1)
                return nums[pivotIdx];

            else if (pivotIdx > k - 1)
                r = pivotIdx - 1;

            else
                l = pivotIdx + 1;
        }

        return -1;
    }
};