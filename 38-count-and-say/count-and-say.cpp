class Solution {
public:

    string solve(int n){
        if( n== 1)return "1";

        string prev = solve(n-1);
        string res="";
        int i=0;
        while(i<prev.size()){
            char ch = prev[i];
            int time =0;
            while( i < prev.size() && prev[i] == ch){
                time++;
                i++;
            }
            res+=to_string(time)+ch;

        }
        return res;
    }
    string countAndSay(int n) {
        return solve(n);   
    }
};