/*
You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.
The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.
Return the maximum score of a pair of sightseeing spots.

Example 1:
Input: values = [8,1,5,2,6]
Output: 11
Explanation: i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
Example 2:
Input: values = [1,2]
Output: 2
*/

/// Brute Force

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int ans=INT_MIN;
        for(int i=0;i<n-1;i++){
            for(int j=1;j<n;j++){
                ans=max(ans, (values[i]+values[j]+i-j));
            }
        }
    return ans;
    }
};


/// DP Approach

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int ans=INT_MIN, maxi=values[0], mini=INT_MIN;
        for(int i=1;i<n-1;i++){
            mini=max(mini, values[i]-i);
            ans=max(ans,maxi+mini);
            if(maxi<values[i]+i){
                maxi=values[i]+i;
                mini=INT_MIN;
            }
        }
        mini=max(mini, values[n-1]-n+1);
        ans=max(ans, maxi+mini);
    return ans;
    }
};
