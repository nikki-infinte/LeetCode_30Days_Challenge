class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> unsorted=heights;
        sort(heights.begin(),heights.end());
        int count=0;
        if(unsorted == heights)
        {
            return 0;
        }
        for(int i=0;i< heights.size();i++)
        {
            if(unsorted[i]!=heights[i])
            {
                count++;
            }

        }
        return count;
    }
};