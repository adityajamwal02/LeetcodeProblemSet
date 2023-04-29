/*
You are given a 0-indexed 2D integer array questions where questions[i] = [pointsi, brainpoweri].

The array describes the questions of an exam, where you have to process the questions in order (i.e., starting from question 0) and make a decision whether to solve or skip each question. Solving question i will earn you pointsi points but you will be unable to solve each of the next brainpoweri questions. If you skip question i, you get to make the decision on the next question.
For example, given questions = [[3, 2], [4, 3], [4, 4], [2, 5]]:
If question 0 is solved, you will earn 3 points but you will be unable to solve questions 1 and 2.
If instead, question 0 is skipped and question 1 is solved, you will earn 4 points but you will be unable to solve questions 2 and 3.
Return the maximum points you can earn for the exam.

Example 1:
Input: questions = [[3,2],[4,3],[4,4],[2,5]]
Output: 5
Explanation: The maximum points can be earned by solving questions 0 and 3.
- Solve question 0: Earn 3 points, will be unable to solve the next 2 questions
- Unable to solve questions 1 and 2
- Solve question 3: Earn 2 points
Total points earned: 3 + 2 = 5. There is no other way to earn 5 or more points.

Example 2:
Input: questions = [[1,1],[2,2],[3,3],[4,4],[5,5]]
Output: 7
Explanation: The maximum points can be earned by solving questions 1 and 4.
- Skip question 0
- Solve question 1: Earn 2 points, will be unable to solve the next 2 questions
- Unable to solve questions 2 and 3
- Solve question 4: Earn 5 points
Total points earned: 2 + 5 = 7. There is no other way to earn 7 or more points.
*/

/// Recursion

class Solution {
public:
    long long helper(int i, int n, vector<int> &points, vector<int> &brainpower){
        if(i>=n) return 0;
        long long notpick=helper(i+1,n,points,brainpower);
        long long pick=points[i]+helper(i+brainpower[i]+1,n,points,brainpower);

    return max(pick,notpick);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<int> points(n), brainpower(n);
        for(int i=0;i<n;i++){
            points[i]=questions[i][0];
            brainpower[i]=questions[i][1];
        }
    return helper(0,n,points,brainpower);
    }
};


/// Memoization

class Solution {
public:
    long long helper(int i, int n, vector<int> &points, vector<int> &brainpower, vector<long long> &dp){
        if(i>=n) return 0;
        if(dp[i]!=-1){
            return dp[i];
        }
        long long notpick=helper(i+1,n,points,brainpower,dp);
        long long pick=points[i]+helper(i+brainpower[i]+1,n,points,brainpower,dp);

    return dp[i]=max(pick,notpick);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<int> points(n), brainpower(n);
        vector<long long> dp(n,-1);
        for(int i=0;i<n;i++){
            points[i]=questions[i][0];
            brainpower[i]=questions[i][1];
        }
    return helper(0,n,points,brainpower,dp);
    }
};


/// Tabulation

long long mostPoints(vector<vector<int>> &q) {
    int n = q.size();
    vector<long long> dp(n + 1, 0);
    for(int i = n - 1; i >= 0; i--) {
        long long  notPick = dp[i + 1];
        long long pick = q[i][0] + ((i + q[i][1] + 1 <= n) ? dp[i + q[i][1] + 1] : 0);
        dp[i] = max(pick, notPick);
    }

    return dp[0];
}
