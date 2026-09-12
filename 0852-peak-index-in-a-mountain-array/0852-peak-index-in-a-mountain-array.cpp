class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] < arr[mid + 1]) {
                // Increasing part → peak right side me hai
                low = mid + 1;
            }
            else {
                // Decreasing part → peak mid ya left side me hai
                high = mid;
            }
        }

        return low;
    }
};