class Solution {
public:

  bool binary_search(vector<int>& nums, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;  // Prevent overflow

            if (nums[mid] == target) {
                return true;  // Target found
            } else if (nums[mid] < target) {
                low = mid + 1;  // Search in the right half
            } else {
                high = mid - 1;  // Search in the left half
            }
        }
        return false;  // Target not found
    }

    bool search(vector<int>& nums, int target) {
         if (nums.empty()||(nums.size()==1 && nums[0]!=target)) return false;  // Handle empty array case

    if(nums.size()==1)
    {
        if(nums[0]==target)
        {
            return true;
        }
    }
        // Determine the peak point (pivot)
        int peak = -1;
        for (int i = 0; i < nums.size() - 1; i++) {  // Adjust loop condition
            if (nums[i] > nums[i + 1]) {
                peak = i;
                break;
            }
        }
        int n = nums.size();

        // If no rotation (array is fully sorted), set peak to last index
        if (peak == -1) peak = n - 1;

        // Binary search in the appropriate half
        if (target >= nums[0] && target <= nums[peak]) {
            return binary_search(nums, 0, peak, target);
        } else {
            return binary_search(nums, peak + 1, n - 1, target);
        }

        return false;  // Target not found
    }
};