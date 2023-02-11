/*
You are given an integer n, the number of nodes in a directed graph where the nodes are labeled from 0 to n - 1. Each edge is red or blue in this graph, and there could be self-edges and parallel edges.
You are given two arrays redEdges and blueEdges where:
redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and
blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.
Return an array answer of length n, where each answer[x] is the length of the shortest path from node 0 to node x such that the edge colors alternate along the path, or -1 if such a path does not exist.

Example 1:
Input: n = 3, redEdges = [[0,1],[1,2]], blueEdges = []
Output: [0,1,-1]

Example 2:
Input: n = 3, redEdges = [[0,1]], blueEdges = [[2,1]]
Output: [0,1,-1]
*/


class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto red: redEdges){
            adj[red[0]].push_back({red[1], 0});
        }
        for(auto blue: blueEdges){
            adj[blue[0]].push_back({blue[1],1});
        }
        vector<int> ans(n,-1);
        vector<vector<bool>> vis(n, vector<bool>(2));
        queue<vector<int>> q;
        q.push({0,0,-1});
        vis[0][1]=vis[0][0]=true;
        ans[0]=0;
        while(!q.empty()){
            auto front=q.front();
            int node=front[0], steps=front[1], prevColor=front[2];
            q.pop();
            for(auto [near, color] : adj[node]){
                if(!vis[near][color] and color!=prevColor){
                    vis[near][color]=true;
                    q.push({near, 1+steps, color});
                    if(ans[near]==-1){
                        ans[near]=1+steps;
                    }
                }
            }
        }
    return ans;
    }
};
