class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        //step 1: keep unorderd_map with count;
        unordered_map<string,int>mp;
       for(int i=0;i<arr.size();i++)
       {
        mp[arr[i]]++;
      
       }

        //traverse map and which ever with count 1 store in previous arr
        vector<string> unique;
        for (const auto& str : arr) {
            if (mp[str] == 1) {
                unique.push_back(str);
            }
        }
      if(unique.size() >= k)
      {
        return unique[k-1];
      }

      return "";
    }
};