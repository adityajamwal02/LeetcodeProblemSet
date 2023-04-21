/*
Given a collection of Intervals, the task is to merge all of the overlapping Intervals.

Example 1:
Input:
Intervals = {{1,3},{2,4},{6,8},{9,10}}
Output: {{1, 4}, {6, 8}, {9, 10}}
Explanation: Given intervals: [1,3],[2,4]
[6,8],[9,10], we have only two overlapping
intervals here,[1,3] and [2,4]. Therefore
we will merge these two and return [1,4],
[6,8], [9,10].

Example 2:
Input:
Intervals = {{6,8},{1,9},{2,4},{4,7}}
Output: {{1, 9}}
Your Task:
Complete the function overlappedInterval() that takes the list N intervals as input parameters and returns sorted list of intervals after merging.

Expected Time Complexity: O(N*Log(N)).
Expected Auxiliary Space: O(Log(N)) or O(N).
*/

 class Solution {
public:
   vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if(intervals.size()==0) return result;
        sort(intervals.begin(),intervals.end());
        result.push_back(intervals[0]);
        for(int i=1,j=0;i<intervals.size();i++){
            int u=intervals[j][0];
            int v=intervals[j][1];
            int p=intervals[i][0];
            int q=intervals[i][1];
            if(result[j][1]>=p){
                result[j][1]=max(q, result[j][1]);
            }else{
                j++;
                result.push_back(intervals[i]);
            }
        }
    return result;
    }
};
