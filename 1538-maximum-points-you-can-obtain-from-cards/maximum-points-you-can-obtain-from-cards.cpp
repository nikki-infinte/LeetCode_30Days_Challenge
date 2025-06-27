class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int maxSum = 0;
        int  n= cardPoints.size();

        for(int i=0;i<k;i++)
        {
            maxSum += cardPoints[i];
        }

        int currSum = maxSum;
        for(int i=1;i<=k ;i++)
        {
            currSum -= cardPoints[k-i];
            currSum += cardPoints[n-i];
            maxSum = max(currSum , maxSum);
        }
        return maxSum;
    }
};