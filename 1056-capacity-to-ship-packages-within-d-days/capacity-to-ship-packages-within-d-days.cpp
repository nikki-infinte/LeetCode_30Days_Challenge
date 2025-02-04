class Solution {
public:


    bool  check(vector<int>& weights ,int mid ,int days )
    {
        int count =0,sum=0;
        for(int i=0;i<weights.size()-1 ;i++)
        {
            sum +=weights[i];
            if(sum + weights[i+1] > mid)
            {
                count ++;
                sum=0;
            }
            if(weights[i] > mid)return false;
        }
        count++;
        return count <=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int low =*max_element(weights.begin(),weights.end());
        int high =accumulate (weights.begin(),weights.end(),0);

        while(low <= high)
        {
            int mid =low +(high-low)/2;

            if(check(weights,mid,days)){
                high =mid-1;
            }else {
                low =mid+1;
            }
        }
        return low;

    }
};