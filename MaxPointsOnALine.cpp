/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.

Example 1:
Input: points = [[1,1],[2,2],[3,3]]
Output: 3

Example 2:
Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
*/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int n=points.size(), count=0;
        for(int i=0;i<n;i++){
            unordered_map<double, int> mp;
            int yAxis=0;
            for(int j=i+1;j<n;j++){
                int dy=points[j][1]-points[i][1];
                int dx=points[j][0]-points[i][0];
                if(dx==0){
                    yAxis++;
                }else{
                    double slope=(double)dy/dx;
                    mp[slope]++;
                }
            }
            for(auto &m : mp){
                count=max(count,m.second);
            }
        count=max(count, yAxis);
        }
    return count+1;
    }
};

