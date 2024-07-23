class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
      std::unordered_map<int, int> frequency;
        for (int num : nums) {
            frequency[num]++;
        }

        // min-heap (priority_queue in C++)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minheap;
        for (const auto& pair : frequency) {
            minheap.push({pair.second, pair.first});
        }

        // Result vector
        std::vector<int> ans;
        while (!minheap.empty()) {
            int currentFreq = minheap.top().first;
            std::vector<int> temp;
            
            // Collect all elements with the same frequency
            while (!minheap.empty() && minheap.top().first == currentFreq) {
                temp.push_back(minheap.top().second);
                minheap.pop();
            }

            // Sort the elements by value in descending order
            std::sort(temp.begin(), temp.end(), std::greater<int>());

            // Add elements to the result
            for (int num : temp) {
                for (int i = 0; i < currentFreq; ++i) {
                    ans.push_back(num);
                }
            }
        }
        return ans;
       
    }
};