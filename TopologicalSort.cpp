/*
Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.

Example 1:
Input:
Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 3, 2, 1, 0.

Example 2:
Input:
Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 5, 4, 2, 1, 3, 0.

Your Task:
You don't need to read input or print anything. Your task is to complete the function topoSort()  which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns an array consisting of a the vertices in Topological order. As there are multiple Topological orders possible, you may return any of them. If your returned topo sort is correct then console output will be 1 else 0.
*/


/// DFS Solution

class Solution
{
	public:

	void dfs(int node, vector<int> adj[], stack<int> &st, int vis[]){
	    vis[node]=1;
	    for(auto it: adj[node]){
	        if(!vis[it]){
	            dfs(it, adj, st, vis);
	        }
	    }
	    st.push(node);
	}

	vector<int> topoSort(int V, vector<int> adj[])
	{
	    int vis[V]={0};
	    stack<int> st;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,adj,st,vis);
	        }
	    }
	    vector<int> result;
	    while(!st.empty()){
	        result.push_back(st.top());
	        st.pop();
	    }
	   return result;
	}
};

/// BFS Solution  (Kahn's Algorithm)

class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[])
	{
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
	 return result;
	}
};


