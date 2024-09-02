class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();
        long total=0;
        for(int i=0;i<n;i++)
        {
            total+=chalk[i];
        }

        int remaning= k%total;
        for(int i=0;i<n;i++)
        {
            if(chalk[i] >remaning)
            {
                return i;
            }
            remaning -=chalk[i];
        }
        return -1;
    }
};