

class Solution {
public:
    int MAH(vector<int> &height){
        stack<int> st;
        int maxA=0;
        int n=height.size();
        for(int i=0;i<=n;i++){
            while(!st.empty() and (i==n or height[st.top()]>=height[i])){
                int h=height[st.top()];
                st.pop();
                int width;
                if(st.empty()){
                    width=i;
                }else{
                    width=i-st.top()-1;
                }
                maxA=max(maxA,h*width);
            }
        st.push(i);
        }
    return maxA;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> height(m,0);
        int maxArea=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    height[j]++;
                }else{
                    height[j]=0;
                }
            }
            int area=MAH(height);
            maxArea=max(area,maxArea);
        }
    return maxArea;
    }
};
