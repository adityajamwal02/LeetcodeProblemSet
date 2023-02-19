/*
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.
We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

Example 1:
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2

Example 2:
Input: times = [[1,2,1]], n = 2, k = 1
Output: 1

Example 3:
Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,1e8);
        dist[k]=0;
        int total_time=0;
        for(int i=0;i<n-1;i++){
            for(auto it: times){
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                if(dist[u]!=1e8 and dist[u]+wt<dist[v]){
                    dist[v]=dist[u]+wt;
                }
            }
        }
        for(int i=1;i<dist.size();i++){
            total_time=max(total_time,dist[i]);
        }
        if(total_time==1e8){
            return -1;
        }
    return total_time;
    }
};
