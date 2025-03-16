class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        

      //  so here ,append exisitng array 
      colors.insert(colors.end() ,colors.begin() , colors.begin() +(k-1));
      int left =0,right =0;
      int n = colors.size();

      int count =0;
      while(right < n)
      {
        if( right > 0 && colors[right] == colors[right-1])
        {
            left = right;
        } 

        if(right - left + 1 >= k)
        {
            count++;
        }

        right ++;
      }
    return count;


    }
};