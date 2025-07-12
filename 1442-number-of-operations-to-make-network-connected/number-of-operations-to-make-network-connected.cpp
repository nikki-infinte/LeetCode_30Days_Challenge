class Solution {
public:


    vector<int>rank;
    vector<int>parent;

    int find(int i){
        if(parent[i] == i)return i;
        return parent[i] = find(parent[i]);
    }


    void union_f(int x,int y){
        int x_par = find(x);
        int y_par = find(y);

        if(x_par == y_par)return ;

        if(rank[x_par]>rank[y_par]){
            parent[y_par] = x_par;
        }else if(rank[x_par] < rank[y_par]){
            parent[x_par] = y_par;
        }else{
            parent[x_par] = y_par;
            rank[y_par]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {

        if(connections.size() < n-1)return -1;
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++){
            parent[i] =i;
        }
        int component = n;
        for(auto &vec:connections){
            if(find(vec[0])  != find(vec[1])){
                union_f(vec[0],vec[1]);
                component--;
            }
        }

        return component-1;

        
    }
};