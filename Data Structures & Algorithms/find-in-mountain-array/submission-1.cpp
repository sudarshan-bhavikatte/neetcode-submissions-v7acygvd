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
    int search(int l, int r, int target, MountainArray &mountainArr) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int val = mountainArr.get(mid);

            if (val == target)
                return mid;
            else if (val < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }

    int reverseSearch(int l, int r, int target, MountainArray &mountainArr) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int val = mountainArr.get(mid);

            if (val == target)
                return mid;
            else if (val < target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }

public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        // Find the peak
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;

            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                l = mid + 1;
            else
                r = mid;
        }

        int peak = l;

        // Search in increasing part
        int ans = search(0, peak, target, mountainArr);
        if (ans != -1)
            return ans;

        // Search in decreasing part
        return reverseSearch(peak + 1, n - 1, target, mountainArr);
    }
}; 