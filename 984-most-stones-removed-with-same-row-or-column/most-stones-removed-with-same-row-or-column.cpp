class Solution {
public:

    vector<int>parent;
    vector<int>rank;

    int find(int i){
        if(parent[i] == i)return i;
        return parent[i] = find(parent[i]);
    }


    void union_f(int x,int y){
        int x_par = find(x);
        int y_par = find(y);

        if(x_par == y_par)return ;

        if(rank[x_par] > rank[y_par]){
            parent[y_par] = x_par;
        }else if(rank[x_par] < rank[y_par]){
            parent[x_par] = y_par;
        }else{
            parent[x_par] = y_par;
            rank[y_par]++;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        
        int n =stones.size();
        parent.resize(n,0);
        rank.resize(n,0);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int compo =0;
        for(int i=0;i<n;i++){
            int r = stones[i][0];
            int c = stones[i][1];
            for(int j=i+1;j<n;j++){
                int r1 = stones[j][0];
                int c1 = stones[j][1];

                if(r == r1 || c==c1){
                    union_f(i,j);
                }
            }
           
        }

        for(int i=0;i<n;i++){
            if(parent[i] == i){
                compo++;
            }
        }
        return n - compo;
    }
};