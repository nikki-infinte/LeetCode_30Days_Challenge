class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        //using two pointer appraoch 

        int low=0;
        int high=numbers.size()-1;
        while(low<high)
        {
            if(numbers[low] + numbers[high] == target)
            {
                return {low+1,high+1};
            }else if(numbers[low]+ numbers[high] > target)
            {
                high--;
            }else{
                low++;
            }
        }
        return {-1,-1};
    }
};