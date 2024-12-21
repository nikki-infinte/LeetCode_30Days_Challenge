class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int>sum(2,0);
        if(nums.size() == 2)
        {
           if(accumulate(nums.begin(),nums.end(),0)==target)
           {
            sum[0]=0;
            sum[1]=1;
           
           }
  
        }

        //strategy of sliding window
        /* sliding window failed why :-------> sliding window check for continuous suubarray*/
        // int i=0;
        // int j=0;
        // int s=0;
        // while(j<nums.size())
        // {
        //     s+=nums[j];
        //     if(j-i+1==2)
        //     {
        //         if(s==target)
        //         {
        //             sum[0]=i;
        //             sum[1]=j;
        //             break;
        //         }
                
              
        //     }
        //       if(s!=target){
                    
        //             s=s-nums[i];
        //             i++;
        //         }
        //     j++;
        // }


        //two sum approach brute force
        
        //using map
        unordered_map<int,int>umap;
        int n=nums.size();
      for(int i=0;i<n;i++)
      {
        umap[nums[i]]=i;
      }

        for(int i=0;i<n;i++)
        {
            if(umap.find(target-nums[i])!=umap.end())
            {
                if(umap[target-nums[i]] !=i)
                {
                    return {i,umap[target-nums[i]]};
                }
            }
        }
        return {0,0};
    }
};