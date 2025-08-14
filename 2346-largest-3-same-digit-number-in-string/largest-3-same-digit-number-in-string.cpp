class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string res ="";
        int maxN =0;
        for(int i=0;i<n-2;i++){
            if(num[i]==num[i+1] && num[i+1] == num[i+2]){
                string triplet = num.substr(i,3);
                 if (res.empty() || triplet > res) {
                    res = triplet;
                }
            }
        }
        return res;
    }
};