class Solution {
public:
    string removeKdigits(string num, int k) {
        
        
        string res ="";
        int n = num.size();
        if(n == k)return "0";
        for(int i=0;i<n;i++){
            if(k==0||res.empty()){
                  res.push_back(num[i]);
            }else{
                 while(res.size() > 0 && res.back() > num[i] && k>0){
                    res.pop_back();
                    k--;
                }
                res.push_back(num[i]);
            }
           
          
        }
        while(k>0){
            res.pop_back();
            k--;
        }
        int i=0;
        while(res[i]=='0'){
            
            i++;
        }
        string ans = res.substr(i,res.length());
        if(ans=="")return "0";
        return ans;
    }
};