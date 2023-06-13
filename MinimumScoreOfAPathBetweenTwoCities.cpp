/*
You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road between cities ai and bi with a distance equal to distancei. The cities graph is not necessarily connected.
The score of a path between two cities is defined as the minimum distance of a road in this path.
Return the minimum possible score of a path between cities 1 and n.
Note:
A path is a sequence of roads between two cities.
It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n multiple times along the path.
The test cases are generated such that there is at least one path between 1 and n.

Example 1:
Input: n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
Output: 5
Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 4. The score of this path is min(9,5) = 5.
It can be shown that no other path has less score.

Example 2:
Input: n = 4, roads = [[1,2,2],[1,3,4],[3,4,7]]
Output: 2
Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 1 -> 3 -> 4. The score of this path is min(2,2,4,7) = 2.
*/

/// DFS Solution

class Solution {
public:
    int result;
    void dfs(int curr, vector<vector<pair<int,int>>> &adj, vector<int> &vis){
        if(vis[curr]==1) return;
        vis[curr]=1;
        for(int i=0;i<adj[curr].size();i++){
            result=min(result,adj[curr][i].second);
            dfs(adj[curr][i].first,adj,vis);
        }
    return;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        result=INT_MAX;
        vector<vector<pair<int,int>>> adj(n+1);
        vector<int> vis(n+1,0);
        for(int i=0; i<roads.size(); i++){
            adj[roads[i][0]].push_back(make_pair(roads[i][1], roads[i][2]));
            adj[roads[i][1]].push_back(make_pair(roads[i][0], roads[i][2]));
        }
        dfs(1,adj,vis);
    return result;
    }
};


/// Union find Algorithm

class Solution {
public:
    vector<int> root, rank;
    
    int find(int x){
        if(x == root[x])
            return root[x];
        return root[x] = find(root[x]);
    }
    
    void createUnion(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX == rootY)
            return;
        if(rank[rootX] < rank[rootY])
            root[rootX] = rootY;
        else if(rank[rootX] > rank[rootY])
            root[rootY] = rootX;
        else{
            root[rootY] = rootX;
            rank[rootX]++;
        }
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        root.resize(n + 1);
        rank.resize(n + 1);
        for(int i = 0; i < n; i++){
            root[i] = i;
            rank[i] = 0;
        }
        int minScore = INT_MAX;
        for (auto road : roads) {
            createUnion(road[0], road[1]);
        }
        for (auto road : roads) {
            int root1 = find(1);
            int rootX = find(road[0]);
            int rootY = find(road[1]);
            if (root1 == rootX && root1 == rootY) {
                minScore = min(minScore, road[2]);
            }
        }
        return minScore;
    }
};
