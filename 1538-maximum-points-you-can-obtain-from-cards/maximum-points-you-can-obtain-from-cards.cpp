class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //special sliding s=window approach 

        //edge case
        int n=cardPoints.size();
        if(n == k)
        {
            return accumulate(cardPoints.begin(),cardPoints.end(),0);
        }
        
        int i=0;
        int sum=0;
         for(;i<k;i++){
             sum+=cardPoints[i];
         }
         i--;
         int maxsum=sum;
         int j=(n-1);
         while(i>=0)
         {
            sum=sum-cardPoints[i];
            i--;
            sum+=cardPoints[j];
            j--;
            maxsum=max(maxsum,sum);
         }
         return maxsum;
    }
};