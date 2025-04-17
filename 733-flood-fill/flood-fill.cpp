class Solution {
public:
  int n, m;

bool isValid(int x, int y, vector<vector<int>>& image, int org) {
    return (x >= 0 && x < n && y >= 0 && y < m && image[x][y] == org);
}

    void DFS(vector<vector<int>>&image , int sr , int sc , int color,int org)
    {
        image[sr][sc] = color;

      int dx[] = {-1, 0, 1, 0};
        int dy[] = { 0, 1, 0, -1};
        for(int i=0;i<4;i++)
        {
            int newx = sr+dx[i];
            int newy = sc+dy[i];

            if(isValid(newx,newy,image,org))
            {
                DFS(image,newx,newy,color,org);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size();
        m = image[0].size();

        int org = image[sr][sc];
       if (org != color) {
            DFS(image, sr, sc, color, org);
        }
         return image;

    }
};