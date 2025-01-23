class Solution {
public:
    int min_elm(unordered_map<char,int>& umap)
    {
        int ans=INT_MAX;
        for(auto a:umap)
        {
            ans=min(a.second,ans);
        }
        return ans;

    }
     int max_elm(unordered_map<char,int>& umap)
    {
        int ans=INT_MIN;
        for(auto a:umap)
        {
            ans=max(a.second,ans);
        }
        return ans;

    }
    int beautySum(string s) {
        //using two pointer approach 
    
        int n=s.length();
       
        int sum=0;
        for(int i=0;i<n;i++)
        { unordered_map<char, int >mp;
            
            for(int j=i;j<n;j++)
            {
                 mp[s[j]]++; // Add current character to the frequency map

                // Find the minimum and maximum frequency in the map
                int minelem = min_elm(mp);
                int maxelem = max_elm(mp);

                // Add the beauty value (max - min) to the total sum
                sum += (maxelem - minelem);
            }

        }
        return sum;
    }
};