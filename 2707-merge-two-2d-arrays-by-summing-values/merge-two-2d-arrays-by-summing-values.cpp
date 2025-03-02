class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        
        
        int n = nums1.size() ;
        int m = nums2.size() ;
        vector<vector<int>> vec;
       int i=0;
       int j = 0;
       while( i < n && j< m)
       {
        if( nums1[i][0] == nums2[j][0])
        {
            int elem = nums1[i][1]+nums2[j][1];
            vec.push_back({nums1[i][0],elem});
            i++;
            j++;
        }else if( nums1[i][0] < nums2[j][0])
        {
            vec.push_back(nums1[i]);
            i++;
        }else {
            vec.push_back(nums2[j]);
            j++;
        }

       }

       while( i < n)
       {
        vec.push_back(nums1[i]);
        i++;
       }

       while(j < m)
       {
        vec.push_back(nums2[j]);
        j++;
       }

       return vec;
    }
};