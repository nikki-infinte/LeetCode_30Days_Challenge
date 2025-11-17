class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        
        int i=0,j=0;
        int n = nums.size();
        while(i<n && nums[i] == 0){
            i++;
            j++;
        }
        while( j < n){

            if(i<j && nums[j] == 1 ){
              
                if(j-i-1 < k)return false;
                i=j;
            }
            j++;
        }

        return true;
    }
};