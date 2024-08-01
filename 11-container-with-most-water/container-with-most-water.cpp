/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <math.h>

class Solution {
public:
    int maxArea(vector<int>& height) {
        
     int left =0;
     int right=height.size()-1;
     int maxwater=0;

     while(left <=right)
     {
        int width=right-left;
        int currheight=min(height[left],height[right]);
        int curr_area=width*currheight;

        maxwater=max(maxwater,curr_area);

        if(height[left] < height[right])
        {
            left+=1;
        }else{
            right-=1;
        }
     }
    return maxwater;
        
    }
};