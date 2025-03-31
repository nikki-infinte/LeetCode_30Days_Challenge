class Solution {
public:

    bool isValid(string s)
    {
       if (s.length() > 1 && s[0] == '0') return false; // No leading zeros allowed
        if (stoi(s) >= 0 && stoi(s) <= 255) return true;
        return false;
    }
    void solve( int indx , int parts ,string curr,string &s,vector<string>&res)
    {

        
        if(indx >= s.length()   && parts == 4)
        {
             res.push_back(curr.substr(0, curr.length() - 1)); 
            return ;
        }

        if (parts >= 4 || indx >= s.length()) return;
            if (indx + 1 <= s.length()) {
            solve(indx + 1, parts + 1, curr + s.substr(indx, 1) + ".", s, res);
        }

        if (indx + 2 <= s.length() && isValid(s.substr(indx, 2))) {
            solve(indx + 2, parts + 1, curr + s.substr(indx, 2) + ".", s, res);
        }

        if (indx + 3 <= s.length() && isValid(s.substr(indx, 3))) {
            solve(indx + 3, parts + 1, curr + s.substr(indx, 3) + ".", s, res);
        }

}
    
    vector<string> restoreIpAddresses(string s) {

        if(s.length() > 12)return {};
       int indx =0;int parts =0;
       vector<string>res;
       string curr="";
       solve(indx,parts,curr,s,res);

       return res;
    }
};