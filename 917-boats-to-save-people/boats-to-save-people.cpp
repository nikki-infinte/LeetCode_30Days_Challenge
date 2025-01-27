class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(),people.end());
        int n=people.size()-1;
        int low=0;
        int high=n;
        int cnt=0;

        while(low<=high)
        {
            if (low == high) {
                // One person left; needs a separate boat
                cnt++;
                break;
            }
           
            int sum = people[low] +people[high];
            if(sum <= limit)
            {
                low++;
                high--;
                  cnt++;
            }else{
                high--;
                cnt++;
            }
            
        }
      
        return cnt;
    }
};