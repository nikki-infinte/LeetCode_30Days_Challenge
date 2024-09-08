class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
       vector<int>seatarr(101,0);
       vector<int>studentarr(101,0);

      for(int &pos:seats)
      {
        seatarr[pos]++;
      }
      for(int &pos:students)
      {
        studentarr[pos]++;
      }

       int i=0;
       int j=0;
        int moves=0;
        while(i<=100 && j<=100)
        {
            if(seatarr[i]==0)i++;
            if(studentarr[j]==0)j++;

            if(i<=100 && j<=100 &&seatarr[i]!=0 && studentarr[j]!=0 )
            {
                moves+=abs(i-j);
                seatarr[i]--;
                studentarr[j]--;
            }
        }

        return moves;
    }
};