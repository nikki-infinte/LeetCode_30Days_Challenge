class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& images) {
        
        //horizontal reverse
        int n=images.size();
        for(int i=0;i<n;i++)
        {
            int k=0;
            int j=n-1;

            while( k <=j )
            {
                swap(images[i][k],images[i][j]);
                k++;
                j--;
            }
        }

        //invert image
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(images[i][j]==0)
                {
                    images[i][j]=1;
                }else{
                    images[i][j]=0;
                }
            }
        }

        return images;
    }
};