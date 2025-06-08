class Solution {
public:
    vector<int> lexicalOrder(int n) {
        
        vector<string>tmp;
        for(int i=1;i<=n;i++)
        {
            tmp.push_back(to_string(i));
        }

        sort(tmp.begin(),tmp.end());

        vector<int>ans;
        for(int i=0;i<tmp.size();i++)
        {
            ans.push_back(stoi(tmp[i]));
        }
        return ans;
    }
};