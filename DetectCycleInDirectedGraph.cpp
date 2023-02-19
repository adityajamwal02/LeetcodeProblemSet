/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

Example 1:
Input:
Output: 1
Explanation: 3 -> 3 is a cycle

Example 2:
Input:
Output: 0
Explanation: no cycle in the graph
Your task:
You dont need to read input or print anything. Your task is to complete the function isCyclic() which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the given directed graph contains a cycle or not.

Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)
*/


/// DFS Solution (Visited Array and Path Visited Array)

class Solution {
  public:
    bool dfs(int node, vector<int> adj[], int vis[], int pathVis[]){
        vis[node]=1;
        pathVis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pathVis)==true){
                    return true;
                }
            }else if(pathVis[it]){
                return true;
            }
        }
    pathVis[node]=0;
    return false;
    }

    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V]={0};
        int pathVis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathVis)==true) return true;
            }
        }
    return false;
    }
};

/// Using Kahn's Algorithm (BFS Solution)


class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        queue<int> q;
        vector<int> result;
        int indegree[V]={0};
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            result.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(result.size()<V){
            return true;
        }
    return false;
    }
};


