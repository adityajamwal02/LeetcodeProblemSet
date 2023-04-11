/*
Given a Graph of V vertices and E edges and another edge(c - d), the task is to find if the given edge is a Bridge. i.e., removing the edge disconnects the graph.

Example 1:
Input:
c = 1, d = 2
Output:
1
Explanation:
From the graph, we can clearly see that
blocking the edge 1-2 will result in
disconnection of the graph. So, it is
a Bridge and thus the Output 1.

Example 2:
Input:
c = 0, d = 2
Output:
0
Explanation:
blocking the edge between nodes 0 and 2
won't affect the connectivity of the graph.
So, it's not a Bridge Edge. All the Bridge
Edges in the graph are marked with a blue
line in the above image.

Your Task:
You don't need to read input or print anything. Your task is to complete the function isBridge()  which takes number of vertices V, the number of edges E, an adjacency lsit adj and two integers c and d denoting the edge as input parameters and returns 1 if the given edge c-d is a Bridge. Else, it returns 0.
*/


/// Tarjans Algorithm

class Solution
{
    private:
    int timer=0;
    void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], vector<int> &tin, vector<int> &low, int &result, int c, int d){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        for(auto it : adj[node]){
            if(it==parent) continue;
            if(vis[it]==0){
                dfs(it,node,vis,adj,tin,low,result,c,d);
                low[node]=min(low[node],low[it]);
                if(low[it]>tin[node] and ((it==c and node==d ) or (it==d and node==c))){
                    result=1;
                }
            }else{
                low[node]=min(low[node],low[it]);
            }
        }
    }
	public:
    int isBridge(int V, vector<int> adj[], int c, int d)
    {
        int result=0;
        vector<int> vis(V,0), tin(V,0), low(V,0);
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                dfs(i,-1,vis,adj,tin,low,result,c,d);
            }
        }
    return result;
    }
};
