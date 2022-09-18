/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9
*/


class Solution {
public:
    int trap(vector<int>& height) {
        int i=0,n=height.size(),j=n-1;
        int result=0;
        int maxLeft=0, maxRight=0;

        while(i<=j){
            if(height[i]<=height[j]){
                if(height[i]>=maxLeft)
                    maxLeft=height[i];
                else
                    result+=maxLeft-height[i];

                i++;
            }else{
                if(height[j]>=maxRight)
                    maxRight=height[j];
                else
                    result+=maxRight-height[j];

                j--;
            }
        }
    return result;
    }
}
