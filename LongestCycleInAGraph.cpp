/*
You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.
The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from node i, then edges[i] == -1.
Return the length of the longest cycle in the graph. If no cycle exists, return -1.
A cycle is a path that starts and ends at the same node.

Example 1:
Input: edges = [3,3,4,2,3]
Output: 3
Explanation: The longest cycle in the graph is the cycle: 2 -> 4 -> 3 -> 2.
The length of this cycle is 3, so 3 is returned.

Example 2:
Input: edges = [2,-1,3,1]
Output: -1
Explanation: There are no cycles in this graph.
*/

/// DFS

class Solution {
public:
    void dfs(vector<int> graph[], int node, vector<int> &vis, int dist, int &res){
        vis[node]=dist++;
        for(auto x: graph[node]){
            if(vis[x]>0){
                res=max(res, vis[node]-vis[x]+1);
            }else if(vis[x]==0){
                dfs(graph,x,vis,dist,res);
            }
        }
        vis[node]=-1;
    return;
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        int res=-1;
        vector<int> vis(n,0);
        vector<int> graph[n];
        for(int i=0;i<n;i++){
            if(edges[i]!=-1){
                graph[i].push_back(edges[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(graph,i,vis,0,res);
            }
        }
    return res;
    }
};
