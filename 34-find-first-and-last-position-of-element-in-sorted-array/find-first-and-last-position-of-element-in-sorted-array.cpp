class Solution {
public:
     int ceil_value(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        int ceil = -1;  // Initialize to -1 for invalid case
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] >= target) {
                ceil = mid;
                high = mid - 1;  // Search in the left half
            } else {
                low = mid + 1;  // Search in the right half
            }
        }
        return ceil;
    }

    int floor_value(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        int floor = -1;  // Initialize to -1 for invalid case
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] <= target) {
                floor = mid;
                low = mid + 1;  // Search in the right half
            } else {
                high = mid - 1;  // Search in the left half
            }
        }
        return floor;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int f=floor_value(nums,target);
        int c=ceil_value(nums,target);
          if (f == -1 || c == -1 || nums[f] != target || nums[c] != target) {
            return {-1, -1};  // Target not found
        }
        return {c,f};
    }
};