class Solution {
public:
    int numSub(string s) {

    //    unordered_map<int,int>mp;
    //    int n = s.length();
    //    vector<int>rank(n,0);

    //    for(int i=0;i<n;i++){
    //         if(s[i] == '1'){

    //             if(i > 0 ){
    //                 rank[i]=rank[i-1]+1;
    //             }else{
    //                 rank[i] = 1;
    //             }

    //             mp[rank[i]]++;
    //         }
    //    } 

    //     long ans=0;
    //     for(auto e:mp){
    //         ans+=(e.first*e.second);
    //     }
    //     return ans;


     const long MOD = 1e9+7;
        long long ans = 0, count = 0;

        for (char c : s) {
            if (c == '1') {
                count++;
            } else {
                ans = (ans + count * (count + 1) / 2) % MOD;
                count = 0;
            }
        }
        ans = (ans + count * (count + 1) / 2) % MOD;
        return ans;
    }
};