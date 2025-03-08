class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        

      int i = 0, j = 0;
        int n = blocks.size();
        int cntW = 0;
        int minW = n;  // Minimum white blocks in any window of size `k`

        while (j < n) {
            if (blocks[j] == 'W') cntW++;

            if ((j - i + 1) == k) {  // Ensure window size is exactly `k`
                minW = min(minW, cntW);
                if (blocks[i] == 'W') {
                    cntW--;
                }
                i++;
            }
            j++;
        }

        return minW;
    }
};