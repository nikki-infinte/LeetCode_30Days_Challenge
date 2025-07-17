class Solution {
public:
    string removeStars(string s) {
        stack<int>inSt;
        int n=s.length();

        for(int i=0;i<n;i++){

            if(s[i] != '*'){
                inSt.push(i);
            }else{
                inSt.pop();
            }
        }
        string ans ="";

        while(!inSt.empty()){
            ans+=s[inSt.top()];
            inSt.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};