class Solution {
public:

    bool coverAll(vector<int>&houses,vector<int>& heaters,int mid){
         int j=0;
        for(int i=0;i<houses.size();i++)
        {
           
            while(j<heaters.size() && heaters[j] + mid < houses[i]){
                j++;
            }
           if(j == heaters.size() || heaters[j] - mid > houses[i]) return false;

        }
        return true;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int low = 0, high =1e9;
        int ans = 0;
        while(low<=high){
            int mid = (low + high) /2;

            if(coverAll(houses,heaters,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};