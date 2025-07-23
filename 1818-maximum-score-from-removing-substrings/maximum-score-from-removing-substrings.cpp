class Solution {
public:
    int abScore(string& s,int x){
        stack<char>st;
        int sc=0;
        string rest="";
        for(int i=0;i<s.length();i++){
            
            if(!st.empty() && st.top()=='a' && s[i]=='b'){
                rest.pop_back();
                st.pop();
                sc+=x;
            }else{
                st.push(s[i]);
                rest+=s[i];
            }
        }
        s = rest;
        return sc;
    }
    int baScore(string& s,int y){
         stack<char>st;
        int sc=0;
        string rest ="";
        for(int i=0;i<s.length();i++){
            
            if(!st.empty() && st.top()=='b' && s[i]=='a'){
                rest.pop_back();
                st.pop();
                sc+=y;
            }
            else{
                st.push(s[i]);
                rest+=s[i];
            }
            

        }
        s= rest;
        return sc;
    }
    int maximumGain(string s, int x, int y) {
        int n = s.length();
        int score=0;
        if (x > y) {
        score += abScore(s, x); 
        score += baScore(s, y); 
    } else {
        score += baScore(s, y); 
        score += abScore(s, x);
    }

        return score;
    }
};