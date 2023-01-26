/*
Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.

Example 1:
Input: timePoints = ["23:59","00:00"]
Output: 1

Example 2:
Input: timePoints = ["00:00","23:59","00:00"]
Output: 0
*/

class Solution {
public:
    int convert(string s){
        int h=stoi(s.substr(0,2));
        int m=stoi(s.substr(3,2));
    return (h*60 + m);
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int> mins;
        for(auto time: timePoints){
            mins.push_back(convert(time));
        }
        sort(mins.begin(), mins.end());
        int ans=INT_MAX;
        int n=timePoints.size();
        for(int i=0;i<n-1;i++){
            int diff=mins[i+1]-mins[i];
            diff=min(diff, 24*60-diff);
            ans=min(ans,diff);
        }
        int diff=mins[n-1]-mins[0];
        diff=min(diff, 24*60-diff);
        ans=min(ans,diff);
    return ans;
    }
};
