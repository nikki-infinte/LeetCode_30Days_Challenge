class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        unordered_map<int,int>freq;
        for(int x:nums)freq[x]++;

        unordered_map<int,int>need;
        for(int n:nums)
        {
            if(freq[n] ==0)continue;
            if(need[n] > 0){
                need[n]--;
                freq[n]--;

                need[n+1]++;
            }  else if(freq[n]>0 && freq[n+1]>0 && freq[n+2]>0){
                freq[n]--;
                freq[n+1]--;
                freq[n+2]--;
                
                //next num needed in subseq.
                need[n+3]++;
            }
            
            //above both condtn is false
            else{
                return false;
            }
        }

        return true;
    }
};