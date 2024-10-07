class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
     //copy 
     vector<int>new_arr=arr;
     unordered_map<int,int>umap;

     sort(new_arr.begin(),new_arr.end());

     //unique
     new_arr.erase(unique(new_arr.begin(),new_arr.end()),new_arr.end());
     for(int i=0;i<new_arr.size();i++)
     {
        umap[new_arr[i]]=i+1;
     }

     for(int i=0;i<arr.size();i++)
     {
        arr[i]=umap[arr[i]];
     }
     return arr;


    }
};