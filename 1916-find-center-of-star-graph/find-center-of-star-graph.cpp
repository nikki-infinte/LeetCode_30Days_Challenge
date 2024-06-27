class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        

        int numberOfNode=edges.size()+1;
        vector<int> nodeDegreeCount(numberOfNode +1 ,0);
        for(const vector<int> &edge: edges)
        {
            nodeDegreeCount[edge[0]]++;
            nodeDegreeCount[edge[1]]++;
        }
        for(int n=1;n<=numberOfNode ; n++)
        {
            if(nodeDegreeCount[n]==edges.size())
            {
                return n;
            }
        }
        return -1;
    }
};