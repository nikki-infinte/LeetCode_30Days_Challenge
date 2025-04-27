class Solution {
public:
    int splitNum(int num) {
        
        string s = to_string(num);
        sort(s.begin(),s.end());

        string num1,nums2;
        for(int i=0;i<s.length();i++)
        {
            if( i % 2 ==0)
            {
                num1+=s[i];
            }else{
                nums2+=s[i];
            }
        }
        return stoi(num1)+stoi(nums2);
    }
};