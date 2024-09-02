class Solution {
    public int chalkReplacer(int[] chalk, int k) {
        long total=0;
        int n=chalk.length;
        for(int i=0;i<n;i++)
        {
            total+=chalk[i];
        }

        int remaning=(int)(k%total);
        for(int i=0;i<n;i++)
        {
            if(remaning <chalk[i])
            {
                return i;
            }
            remaning -=chalk[i];
        }
        return -1;
    }
}