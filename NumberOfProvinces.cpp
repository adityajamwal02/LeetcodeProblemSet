/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b,
and city b is connected directly with city c, then city a is connected indirectly with city c.
A province is a group of directly or indirectly connected cities and no other cities outside of the group.
You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected,
and isConnected[i][j] = 0 otherwise.
Return the total number of provinces.
*/

class Solution {
private:
    void dfs(int node, vector<int> adj[], vector<int> &vis){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it])
                dfs(it, adj, vis);
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        vector<int> adj[v];
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(isConnected[i][j]==1 and i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(v,0);
        int count=0;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                count++;
                dfs(i, adj, vis);
            }
        }
    return count;
    }
};
