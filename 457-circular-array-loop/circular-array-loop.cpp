class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        
        auto next = [&](int i) {
            // Compute next index circularly
            return ((i + nums[i]) % n + n) % n; // add n to handle negative modulus
        };

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) continue; // already visited

            int slow = i, fast = i;
            bool isForward = nums[i] > 0; // direction

            while (true) {
                // move slow pointer
                int nextSlow = next(slow);
                if (nums[nextSlow] == 0 || (nums[nextSlow] > 0) != isForward)
                    break; // direction changed or visited

                // move fast pointer two steps
                int nextFast = next(fast);
                if (nums[nextFast] == 0 || (nums[nextFast] > 0) != isForward)
                    break;
                
                nextFast = next(nextFast);
                if (nums[nextFast] == 0 || (nums[nextFast] > 0) != isForward)
                    break;

                slow = nextSlow;
                fast = nextFast;

                if (slow == fast) {
                    // check for cycle length > 1
                    if (slow == next(slow))
                        break; // 1-element self-loop
                    return true;
                }
            }

            // mark visited as 0 to avoid revisiting same cycle
            int j = i;
            while (nums[j] != 0 && (nums[j] > 0) == isForward) {
                int nxt = next(j);
                nums[j] = 0;
                j = nxt;
            }
        }
        return false;
    }
};
