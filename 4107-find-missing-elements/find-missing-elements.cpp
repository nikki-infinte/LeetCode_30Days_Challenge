class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_map<int,int>umap;
        int smallest =INT_MAX,largest =INT_MIN;
        for(auto elem:nums){
            if(elem < smallest){
                smallest = elem;
            }
            if(elem > largest ){
                largest = elem;
            }
            umap[elem]++;
        }

        vector<int>ans;
        for(int i=smallest+1 ; i<largest;i++){
            if(umap.find(i)==umap.end()){
                ans.push_back(i);
            }
        }
        return ans;

    }
};