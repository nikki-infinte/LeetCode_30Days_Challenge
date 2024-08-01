class Solution {
public:
    int countSeniors(vector<string>& details) {
        string age;
        int count=0;
        for(auto d:details)
        {
        age+=d.substr(11,2);
        cout<<age<<"--";
        int numage=stoi(age);
        age=" ";
        if(numage > 60)
        {
            count++;
        }
        
        }
        return count;
        
    }
};