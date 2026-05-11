class Solution {
public:

    void separateNumber(vector<int>&separateArr, int num){
        stack<int>st;
        while(num > 0){
            st.push(num%10);
            num/=10;
        }
        while(!st.empty()){
            separateArr.push_back(st.top());
            st.pop();
        }
        
    }
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>separateArr;
        for(int i=0;i<nums.size();i++){

            int num = nums[i];
            if(num <= 9){
                separateArr.push_back(num);
            }else{
                separateNumber(separateArr,num);
            }
        }
        return separateArr;
    }
};