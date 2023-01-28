/*
You are given n points in the plane that are all distinct, where points[i] = [xi, yi]. A boomerang is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).
Return the number of boomerangs.

Example 1:
Input: points = [[0,0],[1,0],[2,0]]
Output: 2
Explanation: The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]].

Example 2:
Input: points = [[1,1],[2,2],[3,3]]
Output: 2

Example 3:
Input: points = [[1,1]]
Output: 0
*/


/// Map Solution

class Solution {
public:
    double calculateDist(int a, int b, int c, int d){
        return sqrt(1.0*((d-b)*(d-b) + (c-a)*(c-a)));
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans=0;
        int n=points.size();
        for(int i=0;i<n;i++){
            int a=points[i][0];
            int b=points[i][1];
            unordered_map<double, int> mp;
            for(int j=0;j<n;j++){
                int c=points[j][0];
                int d=points[j][1];
                double dist=calculateDist(a,b,c,d);
                mp[dist]++;
            }
            for(auto it: mp){
                if(it.second>=2){
                    ans+=it.second*(it.second-1);
                }
            }
        }
    return ans;
    }
};
