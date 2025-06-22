class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size() ,m=p.size();

        int countRe = m;
        int i=0,j=0;
        vector<int>start_i;

        unordered_map<char,int>umap;
        for(auto c:p)umap[c]++;

        while(j < n)
        {
            char c = s[j];
            if(umap[c] > 0)
            {
                countRe--;
            }
            umap[c]--;
            j++;

            while(j-i == m)
            {
                if(countRe == 0)
                {
                    start_i.push_back(i);
                }
                umap[s[i]]++;
                if(umap[s[i]] > 0)countRe++;
                i++;
            }
        }
        return start_i;
    }
};