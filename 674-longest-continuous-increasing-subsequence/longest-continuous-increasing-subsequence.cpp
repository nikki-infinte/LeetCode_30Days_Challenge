class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {

       //brute force 
    int n = nums.size();
    int maxlen = 0;
    for(int i=0;i<n;i++){

        int elem = nums[i] , j = i;
        while( j+1 < n && elem < nums[j+1]){
            elem= nums[j+1];
            j++;
        }
        maxlen = max(maxlen , j-i+1);
       } 
       return maxlen;
    }
};