/*
We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.
Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.

Example 1:
Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4] and group2 [2,3].

Example 2:
Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false

Example 3:
Input: n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
*/


class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        if(n<=1 or dislikes.size()==0){
            return 1;
        }
        vector<vector<int>> edges(n+1,vector<int>());
        for(int i=0;i<dislikes.size();i++){
            edges[dislikes[i][0]].push_back(dislikes[i][1]);
            edges[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        vector<int> vis(n+1,-1);
        queue<int> q;
        int curr;
        for(int i=1;i<=n;i++){
            if(vis[i]>-1){
                continue;
            }
            vis[i]=0;
            q.push(i);
            while(!q.empty()){
                curr=q.front();
                q.pop();
                for(int i=0;i<edges[curr].size();i++){
                    if(vis[edges[curr][i]]==-1){
                        q.push(edges[curr][i]);
                        vis[edges[curr][i]]=(!vis[curr]);
                    }else if(vis[edges[curr][i]]==vis[curr]){
                        return 0;
                    }
                }
            }
        }
    return 1;
    }
};



