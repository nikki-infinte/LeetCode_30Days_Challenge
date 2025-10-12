class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        //brute force
        int n = nums.size();
        int ans =0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int a = nums[i];

            for(int j=i+1;j<n-1;j++){
                int b = nums[j];
                
                int low =j+1;
                int high = n-1;
                int cIndx=-1;
                while(low <= high){
                    int mid = (low+high)/2;

                    if(nums[mid] < a+b){
                        cIndx = mid;
                        low =mid+1;
                    }else{
                        high = mid-1;
                    }
                }

                if(cIndx != -1){
                    int count =( cIndx - j );
                    ans+=count;
                }
            }
        }
        return ans;
    }
};