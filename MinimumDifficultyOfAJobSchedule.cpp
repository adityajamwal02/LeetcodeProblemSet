/*
You want to schedule a list of jobs in d days. Jobs are dependent (i.e To work on the ith job, you have to finish all the jobs j where 0 <= j < i).
You have to finish at least one task every day. The difficulty of a job schedule is the sum of difficulties of each day of the d days.
The difficulty of a day is the maximum difficulty of a job done on that day.
You are given an integer array jobDifficulty and an integer d. The difficulty of the ith job is jobDifficulty[i].
Return the minimum difficulty of a job schedule. If you cannot find a schedule for the jobs return -1.

Example 1:
Input: jobDifficulty = [6,5,4,3,2,1], d = 2
Output: 7
Explanation: First day you can finish the first 5 jobs, total difficulty = 6.
Second day you can finish the last job, total difficulty = 1.
The difficulty of the schedule = 6 + 1 = 7

Example 2:
Input: jobDifficulty = [9,9,9], d = 4
Output: -1
Explanation: If you finish a job per day you will still have a free day. you cannot find a schedule for the given jobs.

Example 3:
Input: jobDifficulty = [1,1,1], d = 3
Output: 3
Explanation: The schedule is one job per day. total difficulty will be 3.
*/

class Solution {
public:
    int mod=1e9+7;

    int solve(vector<int> &jobDifficulty, int d, int start, vector<vector<int>> &dp){
        if(d<0)
            return mod;
        if(start==jobDifficulty.size())
            return d==0 ? 0 : mod;
        if(dp[start][d]!=-1)
            return dp[start][d];

        int ans=INT_MAX, curr_max=jobDifficulty[start];
        for(int i=start;i<jobDifficulty.size();i++){
            curr_max=max(curr_max, jobDifficulty[i]);
            ans=min(ans,curr_max+solve(jobDifficulty,d-1,i+1,dp));
        }
    return dp[start][d]=ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size()<d)
            return -1;
        vector<vector<int>> dp(jobDifficulty.size(), vector<int>(d+1,-1));
        int ans=solve(jobDifficulty, d, 0, dp);
    return ans;
    }
};
