class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
         if (hand.size() % groupSize != 0) return false; // Ensure valid division

        priority_queue<int, vector<int>, greater<int>> pq;

        // Push all elements into the min-heap
        for (int num : hand) {
            pq.push(num);
        }

        while (!pq.empty()) {
            int t = 0;
            int prev = -1;
            vector<int> tmp; // Store duplicates to push back

            while (t < groupSize) {
                if (pq.empty()) return false; // Not enough elements left

                int x = pq.top();
                pq.pop();

                if (t == 0) {
                    prev = x; // First element of the group
                } else {
                    if (x != prev + 1) { 
                        if (x == prev) {
                            tmp.push_back(x);
                            t--;
                             // Store another duplicate
                        } else {
                            return false; // Sequence break
                        }
                    }
                }

                prev = x;
                t++;
            }

            // Push back duplicates that were not used
            for (int val : tmp) {
                pq.push(val);
            }
        }

        return true;
    
    }
};