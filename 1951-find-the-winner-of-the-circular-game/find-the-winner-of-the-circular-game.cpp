class Solution {
public:
    void solve(int index,vector<int>&person,int k)
    {
        if(person.size()<=1)
        {
            return ;
        }
        index=(index+k)%person.size();
        person.erase(person.begin()+index);
        solve(index,person,k);
    }
    int findTheWinner(int n, int k) {
        vector<int>person;
        for(int i=0;i<n;i++)
        {
            person.push_back(i);
        }
        k--;
        solve(0,person,k);
        return person[0]+1;

    }
};