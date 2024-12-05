class Solution {
public:
    bool canChange(string start, string target) {
        
        //use two pointer appraoch i and j to traverse the start and target

        int i=0,j=0,n=start.size();

        while(i<n || j<n)
        {
            while(i<n && start[i]=='_')i++;
            while(j<n && target[j]=='_')j++;

            if(i==n ||j==n)
                break;

            if(start[i]!=target[j])return false;
            if(start[i]==target[j])
            {
                if(start[i]=='L')
                {
                    if(i<j)return false;
                }else {
                    if(i>j)return false;
                }
            }
            i++;
            j++;
           
        }
        return i==n && j==n;
     
    }
};