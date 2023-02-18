/*
Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.

Example 1:
Input:
V = 5, E = 5
adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}}
Output: 1
Explanation:

1->2->3->4->1 is a cycle.
Example 2:

Input:
V = 4, E = 2
adj = {{}, {2}, {1, 3}, {2}}
Output: 0
Explanation:

No cycle in the graph.
Your Task:
You don't need to read or print anything. Your task is to complete the function isCycle() which takes V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the undirected graph contains any cycle or not, return 1 if a cycle is present else return 0.
NOTE: The adjacency list denotes the edges of the graph where edges[i] stores all other vertices to which ith vertex is connected.

Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)
*/


/// BFS

class Solution {
  public:
    bool detectCycle(int node, vector<int> adj[], int vis[]){
        vis[node]=1;
        queue<pair<int,int>> q;
        q.push({node,-1});
        while(!q.empty()){
            int curr=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto it : adj[curr]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it,curr});
                }else if(parent!=it){
                    return true;
                }
            }
        }
    return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        int vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detectCycle(i,adj,vis)==true){
                    return true;
                }
            }
        }
    return false;
    }
};


/// DFS


class Solution {
  public:
    bool dfs(int node, int parent, vector<int> adj[], int vis[]){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(it,node,adj,vis)==true){
                    return true;
                }
            }
            else if(it!=parent) return true;
        }
    return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        int vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,-1,adj,vis)==true){
                    return true;
                }
            }
        }
    return false;
    }
};
