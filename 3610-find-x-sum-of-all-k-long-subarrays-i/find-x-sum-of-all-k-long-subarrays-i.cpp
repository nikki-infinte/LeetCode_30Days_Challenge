class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        
        vector<int>ans;

        int i=0,j=0;
        int n=nums.size();
        
        unordered_map<int,int>umap;
        while(j<n){
            umap[nums[j]]++;
            if(j-i+1 == k){
                
                int sum = 0;
                if(umap.size()<x){
                    
                    for(int l=i;l<=j;l++){
                        sum+=nums[l];
                    }
                }else{

                    //top x from umap
                    //step 1: vector<frequency ,number>
                    vector<pair<int,int>>temp;
                    for (auto &p:umap)temp.push_back({p.second,p.first});

                    //sort 
                    sort(temp.begin(),temp.end(),[](auto &a,auto &b){
                        if(a.first == b.first)return a.second > b.second;
                        return a.first > b.first;
                    });

                    for(int m=0;m<x;m++){
                        sum+=temp[m].first*temp[m].second;
                    }


                }
                ans.push_back(sum);
                umap[nums[i]]--;
                i++;
            }
            j++;
          
        }
        return ans;
    }
};