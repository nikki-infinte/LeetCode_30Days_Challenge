class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int j=numbers.size()-1;
        vector<int>vec;
        while(i<j)
        {
            int des=numbers[i]+numbers[j];
            if(des > target)
            {
                j--;
            }else if(des < target)
            {
                i++;
            }else{
                vec.push_back(i+1);
                vec.push_back(j+1);
                return vec;
            }
        }
       return vec;
    }
};