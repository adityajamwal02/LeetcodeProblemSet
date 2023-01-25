/*
You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.
The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from i, then edges[i] == -1.
You are also given two integers node1 and node2.
Return the index of the node that can be reached from both node1 and node2, such that the maximum between the distance from node1 to that node, and from node2 to that node is minimized. If there are multiple answers, return the node with the smallest index, and if no possible answer exists, return -1.
Note that edges may contain cycles.

Example 1:
Input: edges = [2,2,3,-1], node1 = 0, node2 = 1
Output: 2
Explanation: The distance from node 0 to node 2 is 1, and the distance from node 1 to node 2 is 1.
The maximum of those two distances is 1. It can be proven that we cannot get a node with a smaller maximum distance than 1, so we return node 2.

Example 2:
Input: edges = [1,2,-1], node1 = 0, node2 = 2
Output: 2
Explanation: The distance from node 0 to node 2 is 2, and the distance from node 2 to itself is 0.
The maximum of those two distances is 2. It can be proven that we cannot get a node with a smaller maximum distance than 2, so we return node 2.
*/

class Solution {
	public:
	int closestMeetingNode(vector<int> & edges, int node1, int node2) {
		int n=edges.size();
        vector<int> dist1(n,-1), dist2(n,-1);
        int result=-1;
        int min1=edges.size();
        vector<bool> vis1(n,false), vis2(n,false);
        dfs(edges, dist1, node1, vis1, 0);
        dfs(edges, dist2, node2, vis2, 0);
        int max1=INT_MIN;
        for(int i=0;i<n;i++){
            if(dist1[i]!=-1 and dist2[i]!=-1){
                max1=max(dist1[i], dist2[i]);
                if(max1<min1){
                    min1=max1;
                    result=i;
                }
            }
        }
    return result;
	}
	void dfs(vector<int> & edges, vector<int> & distance1, int node, vector<bool> & visited, int distance) {
		if (node != -1 && visited[node] == false) {
			visited[node] = true;
			distance1[node] = distance;
			dfs(edges, distance1, edges[node], visited, distance + 1);
		}


	}
};
