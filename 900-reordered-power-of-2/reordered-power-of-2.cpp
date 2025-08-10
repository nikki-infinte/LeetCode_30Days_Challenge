class Solution {
public:


    bool recursion(string& n , int i ){
       if( i == n.size()){
            if(n[0] == '0')return false;
            int val =stoi(n);
            return ( (val&(val-1)) == 0);
       }

       for(int j=i;j<n.size();j++){
            swap(n[j],n[i]);
             if (recursion(n, i + 1)) return true; 
            swap(n[j],n[i]);
       }
       return false;
    }
    bool reorderedPowerOf2(int n) {
        if(n < 0) return false;
        string tmp = to_string(n); 
        return ( recursion(tmp,0) );
    }
};