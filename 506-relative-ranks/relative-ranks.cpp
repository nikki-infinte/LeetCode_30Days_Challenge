class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        priority_queue< pair<int,int>>p;

        for(int i=0;i<score.size();i++)
        {
            p.push({score[i],i});
        }


        vector<string>ans(score.size());
        int i=1;
        while(!p.empty())
        {
            pair<int,int>tmp = p.top();
            p.pop();

            if( i == 1 )
            {
                ans[tmp.second]="Gold Medal";
            }else if( i == 2)
            {
                ans[tmp.second] = "Silver Medal";
            }else if( i == 3)
            {
                ans[tmp.second]="Bronze Medal";
            }
            else{
                ans[tmp.second]=to_string(i);
            }
            i++;
        

        }
        return ans;
    }
};