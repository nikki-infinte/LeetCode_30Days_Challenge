class Solution {
public:
    void DFS(vector<vector<int>>& image , int i,int j ,int m, int n,int newc,int oldc)
    {

        vector<int>dx = {1,-1,0,0};
        vector<int>dy = {0,0,-1,1};

        if(image[i][j] == oldc){
            image[i][j] = newc;
            

            for(int k = 0; k< 4;k++)
            {
                int newx = dx[k] + i;
                int newy = dy[k]  + j;

                if(newx >= 0 && newy >= 0 && newx <n && newy < m  && image[newx][newy] == oldc){
                    DFS(image,newx,newy,m,n,newc,oldc);
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)    {
        int n = image.size();
        int m = image[0].size();

         if (image[sr][sc] != color) {
            DFS(image, sr, sc,  m,n, color, image[sr][sc]);
        }
        return image;
    }
};