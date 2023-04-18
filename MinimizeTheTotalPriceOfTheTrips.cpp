/*
There exists an undirected and unrooted tree with n nodes indexed from 0 to n - 1. You are given the integer n and a 2D integer array edges of length n - 1, where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
Each node has an associated price. You are given an integer array price, where price[i] is the price of the ith node.
The price sum of a given path is the sum of the prices of all nodes lying on that path.
Additionally, you are given a 2D integer array trips, where trips[i] = [starti, endi] indicates that you start the ith trip from the node starti and travel to the node endi by any path you like.
Before performing your first trip, you can choose some non-adjacent nodes and halve the prices.
Return the minimum total price sum to perform all the given trips.

Example 1:
Input: n = 4, edges = [[0,1],[1,2],[1,3]], price = [2,2,10,6], trips = [[0,3],[2,1],[2,3]]
Output: 23
Explanation: The diagram above denotes the tree after rooting it at node 2. The first part shows the initial tree and the second part shows the tree after choosing nodes 0, 2, and 3, and making their price half.
For the 1st trip, we choose path [0,1,3]. The price sum of that path is 1 + 2 + 3 = 6.
For the 2nd trip, we choose path [2,1]. The price sum of that path is 2 + 5 = 7.
For the 3rd trip, we choose path [2,1,3]. The price sum of that path is 5 + 2 + 3 = 10.
The total price sum of all trips is 6 + 7 + 10 = 23.
It can be proven, that 23 is the minimum answer that we can achieve.

Example 2:
Input: n = 2, edges = [[0,1]], price = [2,2], trips = [[0,0]]
Output: 1
Explanation: The diagram above denotes the tree after rooting it at node 0. The first part shows the initial tree and the second part shows the tree after choosing node 0, and making its price half.
For the 1st trip, we choose path [0]. The price sum of that path is 1.
The total price sum of all trips is 1. It can be proven, that 1 is the minimum answer that we can achieve.
*/

/// DP ON TREES (DFS)

class Solution {
public:
    int dp[51][2];

    void helper(int node, vector<int>&curr, vector<int>&contribution, int end, vector<vector<int>> &adj, int p){
        curr.push_back(node);
        if(end==node){
            for(auto it : curr){
                contribution[it]++;
            }
            curr.pop_back();
            return;
        }
        for(auto ch : adj[node]){
            if(ch!=p) helper(ch,curr,contribution,end,adj,node);
        }
    curr.pop_back();
    }

    int dfs(vector<int>& contri,vector<int>& pr,int node,vector<vector<int>>& g,int p=-1,bool parentHalved=false){
        int res1=(contri[node]*pr[node])/2,res2=contri[node]*pr[node];

        if(dp[node][parentHalved]!=-1)   return dp[node][parentHalved];

        for(auto& ch:g[node])   if(ch!=p)   res2+=dfs(contri,pr,ch,g,node,0);
        if(parentHalved) return dp[node][parentHalved]=res2;

        for(auto& ch:g[node])   if(ch!=p)    res1+=dfs(contri,pr,ch,g,node,1);
        return dp[node][parentHalved]=min(res1,res2);
    }

    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<vector<int>> adj(n);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> contribution(n,0);
        memset(dp,-1,sizeof(dp));
        for(auto trip : trips){
            vector<int> curr;
            helper(trip[0],curr,contribution,trip[1],adj,-1);
        }
    return dfs(contribution,price,0,adj,-1,0);
    }
};
