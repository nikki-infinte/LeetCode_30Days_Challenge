class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        int orignal = count(nums.begin(),nums.end(),k);
        int mx= 0;

        for (int m=1 ;m <=50;++m)
        {
            if( m == k)continue;
            int curr = 0,maxCur=0;
            for(int n: nums)
            {
                curr += (n == m)?1 : n == k? -1 :0;
                curr=max(curr,0);
                maxCur = max(maxCur, curr);
            }
            mx = max(mx,maxCur);
        }
        return orignal + mx;
    }
};