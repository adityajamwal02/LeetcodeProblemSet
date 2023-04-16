/*
You have an undirected, connected graph of n nodes labeled from 0 to n - 1. You are given an array graph where graph[i] is a list of all the nodes connected with node i by an edge.
Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.

Example 1:
Input: graph = [[1,2,3],[0],[0],[0]]
Output: 4
Explanation: One possible path is [1,0,2,0,3]

Example 2:
Input: graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
Output: 4
Explanation: One possible path is [0,1,4,2,3]
*/

/// Without BitMask

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n==1) return 0;
        set<pair<int,string>> vis;
        queue<pair<int,string>> q;
        string curr(n,'0');
        string allVisit(n,'1');
        for(int i=0;i<n;i++){
            curr[i]='1';
            q.push({i,curr});
            vis.insert({i,curr});
            curr[i]='0';
        }
        int step=0;
        char temp;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int node=q.front().first;
                curr=q.front().second;
                q.pop();
                for(int i=0;i<graph[node].size();i++){
                    temp=curr[graph[node][i]];
                    curr[graph[node][i]]='1';
                    if(curr==allVisit) return step+1;
                    if(!vis.count({graph[node][i],curr})){
                        q.push({graph[node][i],curr});
                        vis.insert({graph[node][i],curr});
                    }
                    curr[graph[node][i]]=temp;
                }
            }
            step++;
        }
    return -1;
    }
};


/// With Bitmask

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n==1) return 0;
        set<pair<int,int>>vis;
        queue<pair<int,pair<int,int>>>q;
        int all=(1<<n)-1;
        for(int i=0;i<n;i++){
            int mask=1<<i;
            q.push({i,{0,mask}});
            vis.insert({i,mask});
        }
        while(!q.empty()){
            int node=q.front().first;
            int dist=q.front().second.first;
            int mask=q.front().second.second;
            q.pop();
            for(auto it:graph[node]){
                int newMask=(mask|(1<<it));
                if(newMask==all)
                    return dist+1;
                else if(vis.count({it,newMask}))
                    continue;
                q.push({it,{dist+1,newMask}});
                vis.insert({it,newMask});
            }
        }
        return 0;
    }
};
