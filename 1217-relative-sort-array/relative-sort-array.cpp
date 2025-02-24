class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        unordered_map<int, int> umap;
        
        // Count occurrences of elements in arr1
        for (int num : arr1) {
            umap[num]++;
        }

        // Add elements that are in arr2 in the correct order
        for (int num : arr2) {
            while (umap[num] > 0) {
                ans.push_back(num);
                umap[num]--;
            }
            umap.erase(num); // Remove processed element from map
        }

        // Store remaining elements that were not in arr2
        vector<int> remaining;
        for (auto& [num, count] : umap) {
            while (count-- > 0) {
                remaining.push_back(num);
            }
        }

        // Sort the remaining elements
        sort(remaining.begin(), remaining.end());

        // Append remaining elements to ans
        ans.insert(ans.end(), remaining.begin(), remaining.end());

        return ans;
    }
};
