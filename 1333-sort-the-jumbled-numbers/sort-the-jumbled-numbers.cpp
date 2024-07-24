class Solution {
public:
     string getMapnum(string &num,vector<int>&mapping)
     {
        string mappedNum="";
        for(int i=0;i<num.length();i++)
        {
            char ch=num[i];
            int id=ch-'0';
            mappedNum += to_string(mapping[id]);
        }
        return mappedNum;
     }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {

        vector<pair<int,int>>vec;
       for(int i=0;i<nums.size();i++)
       {
        //step1 : convert to string
        string numchar=to_string(nums[i]);
        //step 2: get processed num
        string mapstr=getMapnum(numchar,mapping);
        //convert to sort
        int map=stoi(mapstr);
        vec.push_back({map,i});
       } 

       sort(vec.begin(),vec.end());
       vector<int>ans;
       for(auto p: vec)
       {
        int orgindex=p.second;
        ans.push_back(nums[orgindex]);
       }
       return ans;
    }
};