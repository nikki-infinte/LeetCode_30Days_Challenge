class Solution {
public:
    vector<pair<int,int>>serves={{100,0},{75,25},{50,50},{25,75}};
    double soupTake(int A, int B , vector<vector<double>>&dp){
        if(A<=0 && B<=0)return 0.5;
        if(A<=0)return 1;
        if(B<=0)return 0.0;

        if(dp[A][B] != -1.0)return dp[A][B];
        double prob = 0.0;
        for(auto &p:serves){
            int Ataken = p.first;
            int Btaken = p.second;

            prob += soupTake(A - Ataken , B - Btaken,dp);
        }
        return dp[A][B] = prob*0.25;
    }
    double soupServings(int n) {

        if(n >= 5000)return 1.0;
        vector<vector<double>>dp(n+1,vector<double>(n+1,-1.0));
        return soupTake(n,n,dp);
    }
};