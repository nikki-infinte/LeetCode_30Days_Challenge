class Solution {
public:

   vector<int>parent;
   vector<int>rank;
   
   int find(int i){
       if(i==parent[i])return i;
       return parent[i] = find(parent[i]);
   }
   
   void union_f(int x,int y){
       int x_par = find(x);
       int y_par = find(y);
       
       if(x_par==y_par)return ;
       
       if(rank[x_par] > rank[y_par]){
           parent[y_par] = x_par;
       }else if(rank[x_par] < rank[y_par]){
           parent[x_par] =y_par;
       }else{
           parent[x_par]=y_par;
           rank[y_par]++;
       }
   }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26,0);
        rank.resize(26,0);


        for(int i=0;i<26;i++){
            parent[i] = i;   
        }


        for(string s:equations){
            if(s[1] == '='){
                union_f(s[0]-'a',s[3]-'a');
            }
        }

        
        for(string s:equations){
            if(s[1] == '!'){
               char first = s[0];
               char second = s[3];

               int x_par = find(first-'a');
               int y_par = find(second-'a');
               if(x_par == y_par)return false;
            }
        }
        return true;
    }
};