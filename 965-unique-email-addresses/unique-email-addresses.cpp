class Solution {
public:

    string refined(string email)
    {
        int i=0;
        string ref ="";
        bool f = true;
        while(email[i]!='@')
        {
            if(email[i]=='+'){
                f=false;
            }
           if(f){ 
            if(email[i]!='.' ){
                ref+=email[i];
            }
           }
            i++;
        }

      
        return ref+email.substr(i);
    }
    int numUniqueEmails(vector<string>& emails) {
        

        int n = emails.size();
        set<string>st;
        for(int i=0;i<n;i++)
        {
            string mail = emails[i];
            mail = refined(mail);
            cout<<mail<<endl;
            st.insert(mail);
        }

        return st.size();
    }
};