class Solution {
public:

    void solve(int currNum , int limit , vector<int>&res )
    {

        if(currNum > limit) return;
        res.push_back(currNum);

        for(int i=0;i<=9;i++)
        {
            int append = currNum*10+i;
            if(append > limit){
                return;
            }
            solve(append,limit,res);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int>res;
        for(int startnum =1 ;startnum <= 9 ;startnum++)
        {
            solve(startnum , n ,res);
        }

        return res;
    }
};