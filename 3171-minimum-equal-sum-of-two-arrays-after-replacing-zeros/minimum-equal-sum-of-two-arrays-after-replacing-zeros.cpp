class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        
     long long zero_cnt_n1 =0, zero_cnt_n2 =0;
     for(int i=0;i<nums1.size();i++)
     {
        if(nums1[i] == 0){
            zero_cnt_n1 ++;
            nums1[i]=1;
        }
        
     }
     
    for(int i=0;i<nums2.size();i++)
     {
        if(nums2[i] == 0){
            zero_cnt_n2 ++; 
            nums2[i]=1;
        }  
     }

    long long accumulation1 = accumulate(nums1.begin(),nums1.end(),0LL);
    long long accumulation2 = accumulate(nums2.begin(),nums2.end(),0LL);

    if(accumulation1 > accumulation2 && zero_cnt_n2 == 0)return -1;
    if(accumulation2 > accumulation1 && zero_cnt_n1 == 0)return -1;

    return max(accumulation1 , accumulation2);

     

    }
};