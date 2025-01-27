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

            if(people[low] + people[high] <=limit)
            {
                low++;
            }
            high--;
            cnt++;
        }
       
        return cnt;
    }
};