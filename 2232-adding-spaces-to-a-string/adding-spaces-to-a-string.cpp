class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
  


        string word;
        vector<string>vec;
        unordered_map<int,int>sp;
        for(auto s:spaces)
        {
            sp[s]++;
        }

        for(int i=0;i<s.length();i++)
        {
            if(sp.find(i)!=sp.end())
            {
               vec.push_back(word);
               word="";
              
            }
            word+=s[i];
        }
         if (!word.empty()) {
            vec.push_back(word);
        }

        string ans="";
        for(int i=0;i<vec.size();i++)
        {
            ans+=vec[i];
            if(i==vec.size()-1)continue;
            ans+=" ";
        }
        return ans;
    }
};