class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr2.size();i++){
            mp[arr2[i]] =i;
        }
        sort(arr1.begin(),arr1.end(),[mp]( int a ,  int b){
            int rankA = mp.count(a) ? mp.at(a):1000 +a;
            int rankB =mp.count(b)?mp.at(b):1000+b;

            return rankA < rankB ;
        });
        return arr1;
    }
};