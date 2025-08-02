class Solution {
public:

   char DFS( unordered_map<char,vector<char>>&mp , char toLook , vector<int>&visit)   {

        visit[toLook-'a']=1;
        char minChar = toLook;
        for(auto &neigb : mp[toLook]){
            if(visit[neigb-'a'] == 0){
                minChar= min(minChar,  DFS(mp,neigb,visit));
              
            }
        }
        return minChar;

    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
     

        unordered_map<char,vector<char>>mp;
        for(int i=0;i<n;i++){
            int u = s1[i];
            int v = s2[i];

            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        string s="";
        for(auto ch:baseStr){
            vector<int>visit(26,0);
            s+=DFS(mp,ch,visit);
        }
        return s;
    }
};