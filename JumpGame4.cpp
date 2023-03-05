/*
Given an array of integers arr, you are initially positioned at the first index of the array.
In one step you can jump from index i to index:
i + 1 where: i + 1 < arr.length.
i - 1 where: i - 1 >= 0.
j where: arr[i] == arr[j] and i != j.
Return the minimum number of steps to reach the last index of the array.
Notice that you can not jump outside of the array at any time.

Example 1:
Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
Output: 3
Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.

Example 2:
Input: arr = [7]
Output: 0
Explanation: Start index is the last index. You do not need to jump.

Example 3:
Input: arr = [7,6,9,6,9,6,9,7]
Output: 1
Explanation: You can jump directly from index 0 to index 7 which is last index of the array.
*/


/// BFS + Map Approach ( to mark and store indices )


class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return 0;
        unordered_map<int, vector<int>> mp;
        vector<int> vis(n,0);
        vis[0]=1;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        int counter=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int curr=q.front();
                q.pop();
                if(curr==n-1) return counter;
                if(curr+1 < n and vis[curr+1]!=1){
                    vis[curr+1]=1;
                    q.push(curr+1);
                }
                if(curr-1 >= 0 and vis[curr-1]!=1){
                    vis[curr-1]=1;
                    q.push(curr-1);
                }
                for(int nextIndex : mp[arr[curr]]){
                    if(nextIndex!=curr and vis[nextIndex]!=1){
                        vis[nextIndex]=1;
                        q.push(nextIndex);
                    }
                }
                mp[arr[curr]].clear();
            }
        counter++;
        }
    return -1;
    }
};


/// PQ with DP Solution
class Solution {
public:
   map<int, vector<int>>mp;
    map<int, int>vis;
    int solve(vector<int>& arr)
    {
        int n = arr.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pqe;pqe.push({0, 0});


        int dp[n];for(auto &x:dp) x = INT_MAX;
       dp[0]=0;

        while(pqe.size())
        {
            auto p = pqe.top();pqe.pop();
            int i = p.second+1;
            int j = p.second-1;
            if(i<n && dp[i]>1+dp[p.second])
            {
                dp[i]=1+dp[p.second];pqe.push({1+dp[p.second], i});
            }
            if(j>=0 && dp[j]>dp[p.second]+1)
            {
                dp[j]=dp[p.second]+1;pqe.push({1+dp[p.second], j});
            }
            if(vis.find(arr[p.second])==vis.end())
            {
                for(auto &x:mp[arr[p.second]]) if(dp[x]>1+dp[p.second]) dp[x]=1+dp[p.second], pqe.push({1+dp[p.second], x});
                vis[arr[p.second]]=1;
            }


        }

        return dp[n-1];
    }
    int minJumps(vector<int>& arr) {

        int n = arr.size();
        for(int i=0;i<n;i++) mp[arr[i]].push_back(i);

       return solve(arr);
    }
};
