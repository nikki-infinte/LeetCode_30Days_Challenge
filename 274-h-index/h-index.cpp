class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int n = citations.size();
       
        int h = 0;
       for(int count = 1 ;count <=n;count++)
       {
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
             if (citations[i] >= count) cnt++;
        }
          if (cnt >= count) h = count;
       }

       return h;
    }
};