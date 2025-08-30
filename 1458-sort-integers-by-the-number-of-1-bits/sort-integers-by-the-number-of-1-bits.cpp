class Solution {
public:
    int countSetBit(int num){

        int count =0;
        while( num  > 0){
            num = num & num-1;
            count++;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        map<int,vector<int>>mp;

        for(int x:arr){
            int setBit = countSetBit(x);
            mp[setBit].push_back( x ); 
        }

        vector<int>ans;
        for(auto &a:mp){
            sort(a.second.begin(),a.second.end());
            for(int i=0;i<a.second.size();i++){
                ans.push_back(a.second[i]);
            }
        }
        return ans;
    }
};