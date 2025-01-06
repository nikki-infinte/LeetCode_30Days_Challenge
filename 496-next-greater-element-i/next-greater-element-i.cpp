class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //<elem ,index>
        stack<int>st;
        unordered_map<int,int>umap;
        for(int i=nums2.size()-1;i>=0;i--)
        {
            while(!st.empty() && nums2[i]>=st.top()){
                st.pop();
            }
            if(st.empty())
            {
                umap[nums2[i]]=-1;
            }else{
                umap[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }
        vector<int>ans(nums1.size(),-1);
        for(int i=0;i<nums1.size();i++)
        {
            ans[i]=umap[nums1[i]];
        }
        return ans;
    }
};