class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        
        int  n =arr.size();
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i] % 2)
            {
                if(i>=2)
                {
                    if(arr[i-1]%2 && arr[i-2]%2)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};