/*
You have n gardens, labeled from 1 to n, and an array paths where paths[i] = [xi, yi] describes a bidirectional path between garden xi to garden yi. In each garden, you want to plant one of 4 types of flowers.
All gardens have at most 3 paths coming into or leaving it.
Your task is to choose a flower type for each garden such that, for any two gardens connected by a path, they have different types of flowers.
Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)th garden. The flower types are denoted 1, 2, 3, or 4. It is guaranteed an answer exists.

Example 1:
Input: n = 3, paths = [[1,2],[2,3],[3,1]]
Output: [1,2,3]
Explanation:
Gardens 1 and 2 have different types.
Gardens 2 and 3 have different types.
Gardens 3 and 1 have different types.
Hence, [1,2,3] is a valid answer. Other valid answers include [1,2,4], [1,4,2], and [3,2,1].

Example 2:
Input: n = 4, paths = [[1,2],[3,4]]
Output: [1,2,1,2]

Example 3:
Input: n = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
Output: [1,2,3,4]
*/

class Solution {
public:
    bool isValid(int i, int clr, vector<int> &color, vector<int> adj[]){
        for(auto node : adj[i]){
            if(color[node]==clr) return false;
        }
    return true;
    }

    void solve(int i, vector<int> adj[], vector<int> &vis, vector<int> &color){
        vis[i]=1;
        for(auto node : adj[i]){
            if(!vis[node]){
                for(int j=1;j<=4;j++){
                    if(isValid(node,j,color,adj) and !vis[node]){
                        color[node]=j;
                        solve(node,adj,vis,color);
                    }
                }
            }
        }
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> adj[n+1];
        vector<int> color(n+1), vis(n+1);
        for(auto path : paths){
            int u=path[0];
            int v=path[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                color[i]=1;
                solve(i,adj,vis,color);
            }
        }
    auto it=color.begin();
    color.erase(it);

    return color;
    }
};
