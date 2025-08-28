class Solution {
public:
    int maxArea(vector<int>& height) {
        int mxArea = INT_MIN;

        int left = 0,right = height.size()-1;

        while(left <= right){

            int area = (right - left)*min(height[left],height[right]);
            mxArea = max(mxArea,area);
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }

        }
        return mxArea;
    }
};