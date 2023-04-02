/*
There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1. The edges in the graph are represented by a given 2D integer array edges, where edges[i] = [ui, vi] denotes an edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.
Return the length of the shortest cycle in the graph. If no cycle exists, return -1.
A cycle is a path that starts and ends at the same node, and each edge in the path is used only once.

Example 1:
Input: n = 7, edges = [[0,1],[1,2],[2,0],[3,4],[4,5],[5,6],[6,3]]
Output: 3
Explanation: The cycle with the smallest length is : 0 -> 1 -> 2 -> 0

Example 2:
Input: n = 4, edges = [[0,1],[0,2]]
Output: -1
Explanation: There are no cycles in this graph.
*/

/// BFS Modified

class Solution {
public:

    int solve(int node, vector<vector<int>> &adj){
        int n=adj.size();
        int res=INT_MAX;
        vector<int> level(n,INT_MAX);
        level[node]=0;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto it : adj[curr]){
                if(level[it]==INT_MAX){
                    level[it]=level[curr]+1;
                    q.push(it);
                }else if(level[it]>=level[curr]){
                    return level[curr]+level[it]+1;
                }
            }
        }
    return INT_MAX;
    }

    int findShortestCycle(int n, vector<vector<int>>& edges) {
        int result=INT_MAX;
        vector<vector<int>> graph(n);
        for(auto edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        for(int i=0;i<n;i++){
            int temp=solve(i,graph);
            result=min(result,temp);
        }
    if(result==INT_MAX) return -1;

    return result;
    }
};
