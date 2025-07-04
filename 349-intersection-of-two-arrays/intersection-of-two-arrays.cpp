class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        

        // [ 4,5,9] [4,4,8,9,9] 

        int i=0,j=0;
        int n =nums1.size();
        int m =nums2.size();

        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int>ans;
        // while(i<n && j<m)
        // {
        //     if(nums1[i]==nums2[j] ){
        //          if(ans.empty() || ans.back() != nums1[i]) {
        //             ans.push_back(nums1[i]);
        //         }
        //         i++;
        //         j++;
        //     }else if(nums1[i] > nums2[j]){
        //             j++;   // move forward in nums2
        //         }else {
        //             i++;   // move forward in nums1
        //         }
        // }
        // return ans;

        for(int i=0;i<m;i++){
            if(binary_search(nums1.begin(),nums1.end(),nums2[i])){
                if( (!ans.empty() && ans.back()!= nums2[i]) || ans.empty()){
                    ans.push_back(nums2[i]);
                }
            }
        }
        return ans;
    }
};