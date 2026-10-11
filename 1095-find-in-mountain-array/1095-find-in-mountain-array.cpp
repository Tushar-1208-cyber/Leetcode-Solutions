/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int low = 0;
        int high = n-1;

        // find peak index of mountain
        while(low < high){
            int mid = low + (high - low) / 2;

            // If the array is increasing, peak lies on the right
            if(mountainArr.get(mid) < mountainArr.get(mid + 1)){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }

        // searching target in increasing part (left side)
        int peak = low;
        low = 0;
        high = peak;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(mountainArr.get(mid) == target){
                return mid;
            }
            else if(mountainArr.get(mid) < target){   // Increasing order: target is on the right
                low = mid + 1;
            }
            else{    // Target is on the left
                high = mid - 1;
            }
        }

        // searching target in decreasing part (right side)
        low = peak + 1;
        high = n - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(mountainArr.get(mid) == target){
                return mid;
            }
            else if(mountainArr.get(mid) > target){   // Decreasing order: smaller target lies on the right
                low = mid + 1;
            }
            else{    // Larger target lies on the left
                high = mid - 1;
            }
        }
        return -1;   // Target is not present in the mountain array
    }
};