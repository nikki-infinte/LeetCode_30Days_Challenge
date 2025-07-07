class Solution {
public:

    vector<int>leftMax(int n ,vector<int>& height ){
        vector<int>leftMx(n,0);
        leftMx[0]= height[0];
        for(int i=1;i<n;i++)
        {
            leftMx[i] = max(leftMx[i-1],height[i]);
        }
        return leftMx;
    }

    vector<int> rightMax(int n,vector<int>& height){
        
        vector<int>rightMx(n,0);
        rightMx[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            rightMx[i] = max(rightMx[i+1],height[i]);
        }
        return rightMx;
    }
    int trap(vector<int>& height) {
        
        int sum =0;
        int n = height.size();


        vector<int>leftMx=leftMax(n,height);
        vector<int>rightMx=rightMax(n,height);


        for(int i=0;i<height.size();i++)
        {
            sum+=min(leftMx[i],rightMx[i])-height[i];
        }
        return sum ;
    }
};