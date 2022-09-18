/*
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point.
Check if these points make a straight line in the XY plane.

Example 1:
Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true

Example 2:
Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false
*/

class Solution {
public:
    bool isCollinear(int x1, int y1, int x2, int y2, int x3, int y3){
        int result=x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2);
        return result==0;
    }

    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n=coordinates.size();
        if(n==2)
            return true;
        for(int points=0;points<=n-3;points++){
            vector<int> c1=coordinates[points];
            vector<int> c2=coordinates[points+1];
            vector<int> c3=coordinates[points+2];
            if(!isCollinear(c1[0],c1[1],c2[0],c2[1],c3[0],c3[1])){
                return false;
            }
        }
        return true;
    }
};
