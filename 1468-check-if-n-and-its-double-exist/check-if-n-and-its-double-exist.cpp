class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
    //optimal solution using hash

    unordered_map<int,int>mp;
    for(int i=0;i<arr.size();i++)
    {
        mp[arr[i]]++;
    }

    for(int i=0;i<arr.size();i++)
    {
        int num=arr[i]*2;
        cout<<num<<endl;
        if(mp.find(num)!=mp.end())
        {
            if(num==arr[i])
            {
                if(mp[num] > 1 )
                {
                    return 1;
                }else {
                    continue;
                }
            }
            return true;
        }
    }
    return false;
 }
};