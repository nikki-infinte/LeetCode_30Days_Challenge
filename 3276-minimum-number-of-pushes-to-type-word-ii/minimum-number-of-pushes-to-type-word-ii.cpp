class Solution {
public:
    int minimumPushes(string word) {
        vector<int>arr(26,0);
        //frequency store;
       for(auto w:word)
       {
        arr[w-'a']++;
       }
       sort(arr.begin(),arr.end());

       int count=0;
       int minkeyPress=0;
       for(int i=25;i>=0;i--)
       {
        int mul=0;
        if(count < 8)
        {
            mul=1;
        }else if(count <16)
        {
            mul=2;
        }else if(count <24){
            mul=3;
        }else{
            mul=4;
        }

        int val=arr[i]*mul;
        minkeyPress +=val;
        count++;
       }
       return minkeyPress;

       
    }
};